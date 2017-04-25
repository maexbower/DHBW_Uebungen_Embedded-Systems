#include <stdio.h>
#include "../include/Printf.h"
int main() {
    char destinantion[255];
    for(int i = 0; i < 255; i++)
    {
        destinantion[i] = '\0';
    }
    destinantion[0] = '1';
    destinantion[1] = '2';
    destinantion[2] = '3';
    char tmp[234254] = "Tessd\"$§$xfg  nsfghwr";
    Printf(&destinantion[3], &destinantion[255], "Hallo Welt %s %x Bla %b Baumhaus. %c", tmp, 0xF0000000,0b100000000 , 'g');
    printf("Ergebnis: %s", destinantion);
    return 0;
}