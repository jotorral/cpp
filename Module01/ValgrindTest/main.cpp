#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void){
    int i = 0;
    i = i + 0x30;
    write(1, &i, 1);
    write(1,  "\n", 1);
    return (0);
}
