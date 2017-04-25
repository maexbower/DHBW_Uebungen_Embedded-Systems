//
// Created by max on 23.04.17.
//

#ifndef EMBEDDEDUEBUNGEN03_PREALLOCSTRING_H
#define EMBEDDEDUEBUNGEN03_PREALLOCSTRING_H
#include <cstddef>
#include <cstdarg>
#include "Printf.h"
#define CREATE(varName, size) PreAllocString<size> varName;

template <size_t SIZE>
class PreAllocString{
public:
    PreAllocString()
    {
        Empty();
    }
    operator const char *() const
    {
        return payload;
    }
    operator const void *() const
    {
        return static_cast<void*>(payload);
    }
    const char & operator []( const int idx )
    {
        //ToDo abfrage ob im Bereich
        return payload[idx];
    }
    /* Current number of characters in string */
    size_t GetLength() const
    {
        return static_cast<size_t >(endOfString-payload);
    }
    /* Maximum number of characters possible */
    constexpr size_t SizeOf()
    {
        return SIZE;
    }
    /* Empty the string , set length field to zero */
    void Empty()
    {
        endOfString = payload;
        for(char* tmp = payload; &payload[SIZE] != tmp; tmp++)
        {
            *tmp = '\0';
        }
    }
    PreAllocString & operator =(char rhs)
    {
        Empty();
        *endOfString++ = rhs;
        *endOfString = '\0';
        return *this;
    }
    PreAllocString & operator =(const char * rhs)
    {
        Empty();
        AddFormat("%s", rhs);
        return *this;
    }
    PreAllocString & operator =(char * const rhs)
    {
        Empty();
        AddFormat("%s", rhs);
        return *this;
    }
    PreAllocString & operator +=(char rhs )
    {
        *endOfString++ = rhs;
        *endOfString = '\0';
        return *this;
    }
    PreAllocString & operator +=(char const * rhs)
    {
        AddFormat("%s", rhs);
        return *this;
    }

    void AddFormat(const char * format , ... )
    {
        va_list params;
        va_start(params,format);

        endOfString = Printf(endOfString, &payload[SIZE],format,  params);
        va_end(params);
    }
    void AddWhiteSpace()
    {
        if((GetLength()+1) < SIZE)
        {
            *endOfString++ = ' ';
            *endOfString = '\0';
        }

    }
private:
    char payload[SIZE];
    char* endOfString = payload;
};


#endif //EMBEDDEDUEBUNGEN03_PREALLOCSTRING_H
