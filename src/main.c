#define _POSIX_C_SOURCE 200112L

#include "gpio.h"
#include "macro.h"

#include <signal.h>
#include <unistd.h>
#include <time.h>

char stop = 0;

void fstop(int sigrecu) {
    stop = 1;
}

double now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1e6;
}

int main(void) {

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

	printf("L'interprète écoute ! Ctrl+C pour stop");

	int last_value = -1;
	int value;
	double start_time = 0.0;
	struct timespec ts = {0, 100000000}; // 0s + 100ms

	while (!stop) {
		value = gpiod_line_get_value(gpio.line); //Récupère la valeur de la ligne

		if (value < 0) {	// Vérification d'erreur
        	perror("gpiod_line_get_value");
        	stop = 1;
    	}

		if (value != last_value) { // Détecte un changement d'état
			double current_time = now_ms(); // récupère le temps en ms

			double duration = current_time - start_time; // Durée d'un état

			//Affichage de l'état
            printf("État %d -> %d, durée = %.3f ms\n",
                last_value, value, duration);
			
			// MAJ des variables
            start_time = current_time; 
            last_value = value;
		}

		nanosleep(&ts, NULL); // Sleep pour temporiser la boucle
	}
	
	gpio_close(&gpio); // Libère les GPIOs ouverts

	printf("Fin du programme");

	return EXIT_SUCCESS;
}
