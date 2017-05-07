//
// Created by max on 03.05.17.
//

#include "../include/PoolAllocator.h"


IHeapBase::IHeapBase(
        //Constructor Params
        const size_t HEAP_BLOCKSIZE,
        const size_t HEAP_BLOCKCOUNT,
        uint8_t **data,
        uint8_t* **p_usedFields
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
            usedFields[freeblock][0] = &data[freeblock][0];
            usedFields[freeblock][1] = &data[freeblock][sizeInBytes];
            return data[freeblock];
        }else{


        }

    return 0;
}

size_t IHeapBase::getRemainingBlockSpace (size_t blockNr) const
{
    if(HEAP_BLOCKCOUNT <= blockNr)
    {
        return 0;
    }
    if((usedFields[blockNr][1]) >= data[blockNr])
    {
        return 0;
    }else{
        return (size_t)((data[blockNr]) - (usedFields[blockNr][1]));
    }
}
size_t IHeapBase::getMaximaleGroesseAbBlock(size_t blockNr) const
{
    size_t blockCount = blockNr;
    while(**(usedFields+(blockCount*2)) == 0)
    {
        blockCount++;
    }
    return blockNr-blockCount;
}
size_t IHeapBase::getNextFreeBlock() const
{
    for(size_t i = 0; i < (size_t)HEAP_BLOCKCOUNT; i++)
    {
        if(usedFields[0] == 0)
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
        //ToDo
        //Defrag();
    }
}
size_t IHeapBase::Available () const
{
    uint8_t* **iterator = usedFields;
    uint8_t remainingBlocks = 0;
    while((usedFields + (HEAP_BLOCKCOUNT * 2)) > iterator)
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

