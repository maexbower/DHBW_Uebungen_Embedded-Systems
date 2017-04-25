#include <iostream>
#include "../include/PreAllocString.h"
int main() {
   CREATE(str25, 25);
    printf("Size: %u\n", static_cast<unsigned int>(str25.SizeOf()));
    const char *cstr = "fester string";
    printf("String: %s\n", str25);
    str25 += 'c';
    str25.AddWhiteSpace();
    printf("String: %s\n", str25);
    str25 += "Blabla";
    printf("String: %s\n", str25);
    printf("Length: %u\n", static_cast<unsigned int>(str25.GetLength()));
    str25 += cstr;
    printf("String: %s\n", str25);
    printf("Length: %u\n", static_cast<unsigned int>(str25.GetLength()));


    CREATE(str0, 0);
    printf("Size: %u\n", static_cast<unsigned int>(str0.SizeOf()));
    printf("String: %s\n", str0);
    str0 += 'c';
    str0.AddWhiteSpace();
    printf("String: %s\n", str0);
    str0 += "Blabla";
    printf("String: %s\n", str0);
    printf("Length: %u\n", static_cast<unsigned int>(str0.GetLength()));
    str0 += cstr;
    printf("String: %s\n", str0);
    printf("Length: %u\n", static_cast<unsigned int>(str0.GetLength()));
    CREATE(str1, 1);
    printf("Size: %u\n", static_cast<unsigned int>(str1.SizeOf()));
    printf("String: %s\n", str1);
    str1 += 'c';
    str1.AddWhiteSpace();
    printf("String: %s\n", str1);
    str1 += "Blabla";
    printf("String: %s\n", str1);
    printf("Length: %u\n", static_cast<unsigned int>(str1.GetLength()));
    str1 += cstr;
    printf("String: %s\n", str1);
    printf("Length: %u\n", static_cast<unsigned int>(str1.GetLength()));
    return 0;

/*
    CREATE(test_string_5,5);
    CREATE(test_string_20,20);
    CREATE(test_string_100,100);
    int counter=1;

    printf("-->Test %d. Overflow:\n",counter++);
    */
/* Test overflow *//*

    test_string_5 = "abcdefghijk";
    printf("\t\tInhalt: %s\t Länge: %d\t Maximum: %d\n",\
            (const char*)test_string_5,\
            test_string_5.GetLength(),\
            test_string_5.SizeOf());
    printf("-->Test %d. char operators:\n",counter++);
    */
/* Test operator = for char *//*

    test_string_20 = 'a';
    test_string_20.AddWhiteSpace();
    */
/* Test operator += for char *//*

    test_string_20 += 'b';
    printf("\t\tInhalt: %s\t Länge: %d\t Maximum: %d\n",
           (const char*)test_string_20,
           test_string_20.GetLength(),
           test_string_20.SizeOf());
    printf("-->Test %d. String operators:\n",counter++);
    */
/* Test operator = for char array*//*

    test_string_100 = "abcdef";
    test_string_100.AddWhiteSpace();
    */
/* Test operator += for char array*//*

    test_string_100 += "ghijklo";
    printf("\t\tInhalt: %s\t Länge: %d\t Maximum: %d\n",
           (const char*)test_string_100,
           test_string_100.GetLength(),
           test_string_100.SizeOf());
    printf("-->Test %d. Array operator\n\t\tarray[%d]\t=\tValue: %c\n\t\tarray[%d]\t=\tValue: %c\n",
           counter++,
           1,
           test_string_100[1],
           101,
           test_string_100[101]);
    test_string_100[1];
    printf("\t\tInhalt: %s\t Länge: %d\t Maximum: %d\n",\
            (const char*)test_string_100,\
            test_string_100.GetLength(),\
            test_string_100.SizeOf());
    printf("-->Test %d. indirekt test of AddFormat and Empty:\n",counter++);
    test_string_100="abcdefghijklmnopqrstuvwxyz";
    printf("\t\tInhalt: %s\t Länge: %d\t Maximum: %d\n",\
            (const char*)test_string_100,\
            test_string_100.GetLength(),\
            test_string_100.SizeOf());

    //CREATE(test_string20_2,20);
    */
/*printf("-->Test %d. Copy Class:\n",counter++);
     *test_string20_2="zyxw";
     * fails-->> test_string_20=test_string20_2;
     *//*


    printf("--> Test ENDE \n");
}