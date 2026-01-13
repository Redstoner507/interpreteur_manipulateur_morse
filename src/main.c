#define _POSIX_C_SOURCE 200112L

#include "gpio.h"
#include "macro.h"
#include "interprete.h"

#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

char running = 1;

void fstop(int sigrecu) {
    running = 0;
}

double now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1e6;
}

int main(void) {
	int pipefd[2];

	CHKERR(pipe(pipefd));

	pid_t pid = fork();

	CHKERR(pid);

	if (pid == 0) { // Création d'un fils qui va géré les singaux alternatifs
		close(pipefd[1]); // ferme l'écriture

		CHKERR(interpretSignalStream(pipefd[0]));

		close(pipefd[0]); // ferme le lecteur
		exit(EXIT_SUCCESS);
	}

	close(pipefd[0]); // ferme le lecteur

	GPIO gpio;

	struct sigaction sa1;
	sa1.sa_handler = fstop;
    sigemptyset(&sa1.sa_mask); 
    sa1.sa_flags = 0; 

    if (sigaction(SIGINT, &sa1, NULL) == -1) {
        perror("sigaction");
        return EXIT_FAILURE;
    }

	if (gpio_open(&gpio) == -1) // Ouvre les GPIOs pour la lecture
		return EXIT_FAILURE; 


	int last_value = -1;
	int value;

	double start_time = 0.0;

	struct timespec ts = {0, 100000000}; // 0s + 100ms

	double duration, current_time;
	
	Signal signal;

	printf("L'interprète écoute ! Ctrl+C pour stop\n");

	while (running) {
		value = gpiod_line_get_value(gpio.line); //Récupère la valeur de la ligne

		if (value < 0) {	// Vérification d'erreur
        	perror("gpiod_line_get_value");
        	running = 0;
			continue;
    	}

		if (value != last_value) { // Détecte un changement d'état
			current_time = now_ms(); // récupère le temps en ms

			duration = current_time - start_time; // Durée d'un état

			//Affichage de l'état
            printf("État %d -> %d, durée = %.3f ms\n",
                last_value, value, duration);

			signal.height= value;
			signal.duration = duration;

			write(pipefd[1],&signal,sizeof(signal));
			
			// MAJ des variables
            start_time = current_time; 
            last_value = value;
		}

		nanosleep(&ts, NULL); // Sleep pour temporiser la boucle
	}
	
	close(pipefd[1]); // ferme l'écriture
	gpio_close(&gpio); // Libère les GPIOs ouverts
	wait(NULL); //Attend le fils

	printf("Fin du programme\n");

	return EXIT_SUCCESS;
}
