#include "interprete.h"
#include <math.h>

int interpretSignalStream(int fd) {
    
    ssize_t n;
    Signal signal;
    char buffer[8];

    while ((n = read(fd, &signal, sizeof(Signal))) > 0)
    {
        if (signal.height) // Circuit fermé -> Point et trait
        {
            if (isDuration(signal.duration,DOT)) 
                printf(".");

            else if (isDuration(signal.duration,DASH))
                printf("-");
        }
        else { // Circuit Ouvert -> Séparation
            if (isDuration(signal.duration,SYMBOLE_SPACE))
            {
                
            }
            else if (isDuration(signal.duration,LETTER_SPACE))
            {
                printf(" ");
            }
            else 
            {
                printf(" | ");
            }
        }
    }

    if (n < 0) {
        perror("read");
        return -1;
    }
      
    return 0;
}

/*
    Retourne le caractère correspondant au code passé en paramètre
    Retourne 0 s'il n'existe pas
 */
char morseToChar(const char * morseCode) 
{
    for (size_t i = 0; i < CARACTERES_COUNT; i++)
    {
        MorseEntry entry = morseTable[i];
        if (strcmp(morseCode,entry.morse))
        {
            return entry.letter;
        }
    }
    return 0;
}

static inline bool isDuration(double duration, double target)
{
    return fabs(duration - target) <= TOLERENCE;
}