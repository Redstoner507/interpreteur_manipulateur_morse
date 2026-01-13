#include "interprete.h"

int interpretSignalStream(int fd) {
    
    ssize_t n;
    Signal signal;
    char buffer[8];

    while ((n = read(fd, &signal, sizeof(Signal))) > 0)
    {
        if (signal.height)
        {
            
        }
    }

    if (n < 0) return -1;
      
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