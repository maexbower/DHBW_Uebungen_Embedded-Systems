#include <iostream>
#include "../include/PoolAllocator.h"

int main() {
    CREATE(myData25, 5, 25);
    printf("Heap: %p\n", myData25);
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    //myData25.printData();
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 26byte: %p\n", myData25.Allocate(26));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    printf("remaining Blocks: %u\n", static_cast<unsigned int>(myData25.Available()));
    printf("Alloc 4byte: %p\n", myData25.Allocate(4));
    //myData25.printData();
    CREATE(myData15, 3, 15);
    sprintf((char *)myData15.Allocate(15), "TestStringToWri");
    sprintf((char *)myData15.Allocate(30), "NextStringToWriteInTheCustomStorrage");
    myData15.Deallocate((void *)0xfffffffffff);
    //myData15.printData();

    return 0;
}