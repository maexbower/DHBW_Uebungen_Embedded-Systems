//
// Created by max on 27.03.17.
//

#ifndef EMBEDDEDUEBUNGEN02_PRINTF_H
#define EMBEDDEDUEBUNGEN02_PRINTF_H
#define TOKEN_IDENTIFIER '%'
#define TOKEN_SINT 'd'
#define TOKEN_UINT 'u'
#define TOKEN_CHAR 'c'
#define TOKEN_STRING 's'
#define TOKEN_HEX 'x'
#define TOKEN_BIN 'b'
#define TOKEN_PERCENT '%'
#define TOKEN_ENDOFSTRING '\0'
#define MAX_INT_STELLEN 1000000000
#define MAX_INT_ANZAHL 10
#define FIRST_ASCII_INT 48
#define FIRST_ASCII_ALPH 'A'
    char * Printf ( char * dst , const void * end , const char * fmt , ...) ;
    char * vaPrintf ( char * dst , const void * end , const char * fmt , va_list params) ;
#endif //EMBEDDEDUEBUNGEN02_PRINTF_H
