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

}