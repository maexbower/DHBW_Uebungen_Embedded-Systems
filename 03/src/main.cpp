#include <iostream>
#include "../include/PreAllocString.h"

int main() {
    CREATE(str25,25);
    //str25 += 'c';
    printf("String: %s\n", str25);
    printf("%u", static_cast<unsigned int>(str25.GetLength()));

    return 0;
}