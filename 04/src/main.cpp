#include <stdio.h>
#include "../include/PoolAllocator.h"
#include <string.h>

int main() {
/*    CREATE(myData25, 5, 25);
    CREATE(myData15, 3, 15);
    CREATE(myData1, 1, 1);
    myData15.Deallocate((void *)0xfffffffffff);
    myData15.Deallocate(myData15.Allocate(17));
    myData15.Deallocate(myData15.Allocate(17));
    char tmp[30] = "bla bla bla bla bladghqfhqif";
    char * tmp2 = (char *)myData15.Allocate(sizeof(tmp));
    strcpy(tmp2, tmp);
    printf("TMP2: %s\n",tmp2);
    myData15.printData();
    long test[] = {1234,5235,2354,2354,2356,3657};
    long *test2 = (long *)myData25.Allocate(sizeof(test));
    test2[0] = test[0];
    test2[1] = test[1];
    test2[2] = test[3];
    test2[3] = test[3];
    test2[4] = test[4];
    myData25.printData();
    printf("Long test: %ld, %ld, %ld, %ld", test2[0], test2[1], test2[2], test2[3]);
    myData15.Deallocate(tmp2);
    myData15.printData();
    myData25.printData();*/
    /*CREATE(slotTest, 5,1);
    char* s1 = (char*)slotTest.Allocate(sizeof(char));
    char* s2 = (char*)slotTest.Allocate(sizeof(char));
    char* s3 = (char*)slotTest.Allocate(sizeof(char));
    char* s4 = (char*)slotTest.Allocate(sizeof(char));
    char* s5 = (char*)slotTest.Allocate(sizeof(char));
    char* s6 = (char*)slotTest.Allocate(sizeof(char));
    strcpy(s1, "a");
    strcpy(s2, "b");
    strcpy(s3, "c");
    strcpy(s4, "d");
    strcpy(s5, "e");
    //strcpy(s6, "f");
    slotTest.printData();
    printf("chartest: %s, %s, %s, %s, %s %p\n", s1, s2, s3, s4, s5, (void *) s6);
    slotTest.Deallocate(s2);
    slotTest.Deallocate(s4);
    slotTest.Deallocate(s5);
    slotTest.printData();
    strcpy(s2, "x\0");
    s2 = (char*)slotTest.Allocate(2);
    strcpy(s2, "yz");
    slotTest.printData();*/
    return 0;
}