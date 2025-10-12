#include "gpio.h"
#include "macro.h"

int main(void) {

	GPIO gpio;

	if (gpio_open(&gpio) == -1) // Ouvre les GPIOs pour la lecture
		return EXIT_FAILURE; 

	while (1)
	{
		
	}
	
	gpio_close(&gpio); // Libère les GPIOs ouverts

	return EXIT_SUCCESS;
}
