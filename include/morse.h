#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>

#define CHIPNAME "/dev/gpiochip0"
#define LINE_NUM 21

#define CHK0(op) do { \
    if((op) != 0) { \
        perror(#op); \
        exit(EXIT_FAILURE); \
    } \
} while(0)

#define CHKNULL(op) do { \
    if((op) == NULL) { \
        perror(#op); \
        exit(EXIT_FAILURE); \
    }\
} while(0)

