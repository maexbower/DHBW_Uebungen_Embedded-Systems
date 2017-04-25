#include <stdio.h>
#include "../include/Printf.h"
int main() {
    char destinantion[255];
    for(int i = 0; i < 255; i++)
    {
        destinantion[i] = '\0';
    }
    char tmp[234254] = "Tessd\"$§$xfg  nsfghwr";
    Printf(destinantion, &destinantion[255], "Hallo Welt %s %x Bla %b Baumhaus. %c", tmp, 0xF0000000,0b100000000 , 'g');
    printf("Ergebnis: %s", destinantion);
    return 0;
}