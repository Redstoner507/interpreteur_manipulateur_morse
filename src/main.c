#include "gpio.h"
#include "macro.h"

int main(void) {

	GPIO gpio;

	gpio_open(&gpio); // Ouvre les GPIOs pour la lecture

	gpio_close(&gpio); // Libère les GPIOs ouverts

	return EXIT_SUCCESS;
}
