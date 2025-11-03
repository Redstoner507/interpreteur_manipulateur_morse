#pragma once
#include <gpiod.h>
#include "macro.h"

#define CHIPNAME "/dev/gpiochip0"
#define LINE_NUM 21
#define CONSUMER "interprete"

typedef struct {
    struct gpiod_chip *chip;
    struct gpiod_line *line;
} GPIO;

int gpio_open(GPIO *gpio);
void gpio_close(GPIO *gpio);