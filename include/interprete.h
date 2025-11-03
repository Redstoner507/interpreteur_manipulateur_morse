#pragma once
#include "morse.h"
#include <unistd.h>

typedef struct {
    int hauteurSignal;
    double dureeSignal;
} singalRecu;

int boucleLecture(int fd);