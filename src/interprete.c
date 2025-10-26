#include "interprete.h"

int boucleLecture(int fd) {
    
    ssize_t n;
    double duration;
    char buffer[7];

    while ((n = read(fd, &duration, sizeof(duration))) > 0)
    {
        
    }

    if (n < 0) return -1;  
    return 0;
}