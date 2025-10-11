#include "gpio.h"
#include "macro.h"

int main(void) {
	struct gpiod_chip *chip;
	struct gpiod_line *line;
	
	// Ouvrir le GPIO chip
	CHKNULL(chip = gpiod_chip_open(CHIPNAME));
	// Obtenir la ligne GPIO
	CHKNULL(line = gpiod_chip_get_line(chip,LINE_NUM));

	// Libérer la ligne et fermer le chip
	gpiod_line_release(line);
	gpiod_chip_close(chip);
	return 0;
}
