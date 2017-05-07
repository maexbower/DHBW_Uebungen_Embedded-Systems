//
// Created by max on 03.05.17.
//

#ifndef EMBEDDEDUEBUNGEN04_POOLALLOCATOR_H
#define EMBEDDEDUEBUNGEN04_POOLALLOCATOR_H

#define CREATE(varName, blockCount, blockSize) DataStore<blockSize, blockCount> varName;
#include <cstddef>
#include <cstdint>
class IHeap
{
public :
    virtual void * Allocate ( size_t sizeInBytes ) = 0;
    virtual void   Deallocate ( void *) = 0;
    /* Returns remaining # of available bytes */
    virtual size_t Available () const = 0;

};


class IHeapBase : public IHeap
{
private:
    const size_t HEAP_BLOCKSIZE;
    const size_t HEAP_BLOCKCOUNT;
    uint8_t *data;
    uint8_t* *usedFields;


    //Matrix that stores the Startpointer of each Allocation in [BC][0] and the endpointer in [BC][1]
protected:
    size_t getRemainingBlockSpace (size_t blockNr) const;
    size_t getNextFreeBlock() const;
    size_t getMaximaleGroesseAbBlock(size_t blockNr) const;
    //bool   Defrag ();
public:
    //Constructor Params
    IHeapBase(
            //Constructor Params
            const size_t HEAP_BLOCKSIZE,
            const size_t HEAP_BLOCKCOUNT,
            uint8_t *data,
            uint8_t* *p_usedFields
    );
    size_t getBlockSize() const;
    size_t getBlockCount() const;
    void * Allocate ( size_t sizeInBytes );
    void   Deallocate ( void *);
    void printData();

    /* Returns remaining # of available bytes */
    size_t Available () const;


};

template <size_t BLOCKSIZE, size_t BLOCKCOUNT>
class DataStore : public IHeapBase
{
protected:
    //Data in an Multidimensional Array
    uint8_t data[BLOCKCOUNT][BLOCKSIZE];
    uint8_t* usedFields[BLOCKCOUNT][2];

public:
    DataStore() : IHeapBase(BLOCKSIZE, BLOCKCOUNT, (uint8_t *)data, (uint8_t* *)usedFields )
    {
        for(size_t i = 0; BLOCKCOUNT > i; i++)
        {
            for(size_t b = 0; BLOCKSIZE > b; b++)
            {
                data[i][b] = (uint8_t )1;
            }
            usedFields[i][0] = nullptr;
            usedFields[i][1] = nullptr;
        }
    }
};








#endif //EMBEDDEDUEBUNGEN04_POOLALLOCATOR_H
