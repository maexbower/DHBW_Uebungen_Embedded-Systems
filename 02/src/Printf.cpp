//
// Created by max on 27.03.17.
//

#include <cstdarg>
#include "../include/Printf.h"

char * Printf ( char * dst , const void * end , const char * fmt , ...)
{
    va_list params;
    va_start(params,fmt);
    char * position = dst;
    int inputPosition = 0;

    while((end > position) && (TOKEN_ENDOFSTRING != fmt[inputPosition]))
    {
        if(TOKEN_IDENTIFIER == fmt[inputPosition])
        {
            switch(fmt[++inputPosition]) {
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                case TOKEN_HEX: {
                    unsigned int base = 16;
                    int usedchar = 0;
                    unsigned int uvalcopy = va_arg(params, unsigned int);
                    unsigned int maxuInt32 = 1;
                    int restWert = 0;
                    //Errechne benötigte Anzahl an Stellen
                    while (uvalcopy > maxuInt32) {
                        maxuInt32 *= base;
                        if (maxuInt32 == 0) {
                            //Overflow
                            maxuInt32 = (unsigned int) -1;
                        }
                        usedchar++;
                    }
                    //Wenn der restliche Platz nicht reicht gleich abbrechen
                    if (end <= position + usedchar + 2) {
                        break;
                    }
                    *position++ = '0';
                    *position++ = 'x';
                    if (uvalcopy == 0) {
                        if (end > position) {
                            *position++ = '0';
                        } else {
                            break;
                        }
                    }
                    position += usedchar - 1;
                    while (0 < uvalcopy) {
                        restWert = uvalcopy % base;
                        if (10 > restWert) {
                            *(position--) = (char) (FIRST_ASCII_INT + restWert);
                        } else {
                            *(position--) = (char) (FIRST_ASCII_ALPH + restWert - 10);
                        }

                        uvalcopy /= base;
                    }
                    position += usedchar + 1;
                    break;
                    //va_arg(params, hex);
                    //wird automaitsch als int abgerufen
                }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case TOKEN_BIN: {
                    unsigned int base = 2;
                    int usedchar = 0;
                    unsigned int uvalcopy = va_arg(params, unsigned int);
                    unsigned int maxuInt32 = 1;
                    int restWert = 0;
                    //Errechne benötigte Anzahl an Stellen
                    while (uvalcopy > maxuInt32) {
                        maxuInt32 *= base;
                        usedchar++;
                    }
                    //Wenn der restliche Platz nicht reicht gleich abbrechen
                    if (end <= position + usedchar + 2) {
                        break;
                    }
                    *position++ = '0';
                    *position++ = 'b';
                    if (uvalcopy == 0) {
                        if (end > position) {
                            *position++ = '0';
                        } else {
                            break;
                        }
                    }
                    position += usedchar;
                    while (0 < uvalcopy) {
                        restWert = uvalcopy % base;
                        *position-- = (char) (FIRST_ASCII_INT + restWert);
                        uvalcopy /= base;
                    }
                    position += usedchar + 1;
                    break;
                    //va_arg(params,unsigned int);
                    //wird automaitsch als int abgerufen
                }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                case TOKEN_SINT: {
                    int maxInt32 = MAX_INT_STELLEN;
                    int usedchar = MAX_INT_ANZAHL;
                    bool highestvalreached = false;
                    int valcopy = va_arg(params, int);
                    if (0 > valcopy) {
                        valcopy *= -1;
                        if (end > position) {
                            *position++ = '-';
                        } else {
                            break;
                        }
                    }
                    while (0 < usedchar) {
                        if (((valcopy - maxInt32) >= 0) || (highestvalreached)) {
                            highestvalreached = true;
                            if (end > position) {
                                *position++ = (char) (FIRST_ASCII_INT + (valcopy / maxInt32));
                            } else {
                                break;
                            }
                            valcopy %= maxInt32;
                            usedchar--;
                            maxInt32 /= 10;
                        } else {
                            usedchar--;
                            maxInt32 /= 10;
                        }
                    }
                    break;
                }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                case TOKEN_CHAR:
                    *position++ = va_arg(params, int);
                    break;

                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                case TOKEN_STRING:
                {
                    char *charHelper = va_arg(params, char *);
                    int pos = 0;
                    while (charHelper[pos] != TOKEN_ENDOFSTRING) {
                        if (end > position) {
                            *position++ = charHelper[pos];
                        } else {
                            break;
                        }
                        pos++;
                    }
                    break;
                }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                case TOKEN_UINT:
                {
                    unsigned int maxuInt32 = MAX_INT_STELLEN;
                    int usedchar = MAX_INT_ANZAHL;
                    unsigned int uvalcopy = va_arg(params,unsigned int);
                    bool highestvalreached = false;
                    while(0 < usedchar)
                    {
                        if(((int)(uvalcopy - maxuInt32) >= 0) || (highestvalreached))
                        {
                            highestvalreached = true;
                            if(end > position) {
                                *position++ = (char) (FIRST_ASCII_INT + (uvalcopy / maxuInt32));
                            }else{
                                break;
                            }
                            uvalcopy %= maxuInt32;
                            usedchar--;
                            maxuInt32 /= 10;
                        }else{
                            usedchar--;
                            maxuInt32 /= 10;
                        }
                    }
                    break;
                }
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                case TOKEN_PERCENT:
                    *position = TOKEN_PERCENT;
                    break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                default:
                    position++;
                    //Skip
                    break;
            }
            inputPosition++;
        }else{
            *position++ = fmt[inputPosition++];
        }
    }
    end = '\0';
    return dst;
}
