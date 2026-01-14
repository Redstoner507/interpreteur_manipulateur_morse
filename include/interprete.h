#pragma once
#include "morse.h"
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    char height;
    double duration;
} Signal;

int interpretSignalStream(int fd);

char morseToChar(const char * morseCode);
static inline bool isDuration(double duration, double target);