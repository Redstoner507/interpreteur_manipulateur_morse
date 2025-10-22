#define _POSIX_C_SOURCE 200112L

#include "gpio.h"
#include "macro.h"

#include <signal.h>
#include <unistd.h>


char stop = 0;

void fstop(int sigrecu) {
    stop = 1;
}

int main(void) {

	GPIO gpio;

	struct sigaction sa1;
	sa1.sa_handler = fstop;
    sigemptyset(&sa1.sa_mask); 
    sa1.sa_flags = 0; 

    if (sigaction(SIGINT, &sa1, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

	if (gpio_open(&gpio) == -1) // Ouvre les GPIOs pour la lecture
		return EXIT_FAILURE; 

	while (!stop)
	{
		
	}
	
	gpio_close(&gpio); // Libère les GPIOs ouverts

	return EXIT_SUCCESS;
}
