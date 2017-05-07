#include <iostream>
#include "../include/PoolAllocator.h"

int main() {
    CREATE(myData25, 5, 25);
    printf("Heap: %p\n", myData25);
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    return 0;
}