#include "gpio.h"

int gpio_open(GPIO *gpio) {
    // Ouvrir le GPIO chip
	CHKNULL(gpio->chip = gpiod_chip_open(CHIPNAME));
	// Obtenir la ligne GPIO
	CHKNULL(gpio->line = gpiod_chip_get_line(gpio->chip,LINE_NUM));

    return 0;
}

void gpio_close(GPIO *gpio){
    if (gpio->line)
        gpiod_line_release(gpio->line);
    if (gpio->chip)
        gpiod_chip_close(gpio->chip);
}