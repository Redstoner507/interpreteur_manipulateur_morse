#pragma once
#include "morse.h"
#include <unistd.h>

typedef struct {
    char height;
    double duration;
} Signal;

int interpretSignalStream(int fd);

char morseToChar(const char * morseCode);