#include "interprete.h"

int boucleLecture(int fd) {
    
    ssize_t n;
    singalRecu signal;
    char buffer[8];

    while ((n = read(fd, &signal, sizeof(singalRecu))) > 0)
    {
        
    }

    if (n < 0) return -1;
      
    return 0;
}