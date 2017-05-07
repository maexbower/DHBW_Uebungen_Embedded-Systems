//
// Created by max on 03.05.17.
//
//

#include "../include/PoolAllocator.h"
#ifdef DEBUG
#include <stdio.h>
#endif

IHeapBase::IHeapBase(
            //Constructor Params
            const size_t HEAP_BLOCKSIZE,
            const size_t HEAP_BLOCKCOUNT,
            uint8_t *data,
            uint8_t* *p_usedFields
        ) :
        //Init Consts
        //need to be the same order than in declaration
                HEAP_BLOCKSIZE(HEAP_BLOCKSIZE),
                HEAP_BLOCKCOUNT(HEAP_BLOCKCOUNT),
                data(data)
{
    //Init DataStore Info
    usedFields = p_usedFields;
}
#ifdef DEBUG
void IHeapBase::printData()
{
    uint8_t *ptr = data;
    uint8_t* *usedPtr = usedFields;
    printf("data: %p\n", (void *) ptr);
    for(size_t a = 0; HEAP_BLOCKCOUNT > a; a++, ptr++)
    {
        printf("\t[%u]: %p\n", (unsigned int) a, (void *) ptr);
        printf("\tstart: %p\n", (void *) *usedPtr++);
        printf("\tende: %p\n", (void *) *usedPtr++);
        printf("\t");
        for(size_t b = 0; HEAP_BLOCKSIZE > b; b++, ptr++)
        {
            printf("\t[%u]: %u (%c)", (unsigned int) b, (unsigned int) *(ptr), (char) *(ptr));

        }
        ptr--;
        printf("\n");
    }
}
#endif

void * IHeapBase::Allocate ( size_t sizeInBytes )
{
        size_t requiredBlocks = sizeInBytes / HEAP_BLOCKSIZE;
        if((sizeInBytes % HEAP_BLOCKSIZE) > 0)
        {
            requiredBlocks++;
        }
        if(Available() < requiredBlocks)
        {
            //Not enough space left
            return 0;
        }
        if(requiredBlocks == 1)
        {
            size_t freeblock = getNextFreeBlock();
            usedFields[freeblock*2] = &data[freeblock*HEAP_BLOCKSIZE];
            usedFields[(freeblock*2)+1] = &data[(freeblock*HEAP_BLOCKSIZE)+HEAP_BLOCKSIZE-1];
            return usedFields[freeblock*2];
        }else{
            for(size_t a = 0; HEAP_BLOCKCOUNT > a; a++)
            {
                if(usedFields[2*a] == nullptr)
                {
                    if(requiredBlocks <= getMaximaleGroesseAbBlock(a))
                    {
                        for(size_t b = 0; requiredBlocks > b ; b++)
                        {
                            usedFields[(2*a)+(2*b)] = &data[a*HEAP_BLOCKSIZE];
                            usedFields[(2*a)+(2*b)+1] = &data[(a*HEAP_BLOCKSIZE)+sizeInBytes-1];

                        }
                        return usedFields[2*a];
                    }
                }
            }
        }

    return 0;
}

size_t IHeapBase::getRemainingBlockSpace (size_t blockNr) const
{
    if(HEAP_BLOCKCOUNT <= blockNr)
    {
        return 0;
    }
    if((usedFields[blockNr*2]) >= &data[blockNr*HEAP_BLOCKSIZE])
    {
        return 0;
    }else{
        return (size_t)((&data[blockNr*HEAP_BLOCKSIZE]) - (usedFields[(blockNr*2)+1]));
    }
}
size_t IHeapBase::getMaximaleGroesseAbBlock(size_t blockNr) const
{
    size_t blockCount = blockNr;
    while(usedFields[blockCount*2] == nullptr)
    {
        blockCount++;
    }
    return (blockCount-blockNr);
}
size_t IHeapBase::getNextFreeBlock() const
{
    for(size_t i = 0; i < HEAP_BLOCKCOUNT; i++)
    {
        if(usedFields[i*2] == nullptr)
        {
            return i;
        }
    }
    return 0;
}

void  IHeapBase::Deallocate ( void * ptr)
{
    if(ptr)
    {
        for(size_t a = 0; HEAP_BLOCKCOUNT > a; a++)
        {
            if(usedFields[2*a] == ptr)
            {
                usedFields[2*a] = nullptr;
                usedFields[(2*a)+1] = nullptr;
            }
        }

    }
}
size_t IHeapBase::Available () const
{
    uint8_t* *iterator = usedFields;
    uint8_t remainingBlocks = 0;
    while(usedFields+(HEAP_BLOCKCOUNT*2) > iterator)
    {

        if(nullptr == *iterator)
        {
            remainingBlocks++;
        }
        iterator += 2;
    }
    return remainingBlocks;
}
size_t IHeapBase::getBlockSize() const
{
    return HEAP_BLOCKSIZE;
}
size_t IHeapBase::getBlockCount() const
{
    return HEAP_BLOCKCOUNT;
}

