#include "vector.hh"

namespace cstm
{
    vector::vector() : mSize(0), mData(nullptr)
    {

    }

    vector::vector(size_type size) : mSize(size), mData(nullptr)
    {
        if (mSize != 0)
        {
            mData = new int[mSize];

            for (size_type i = 0; i < mSize; ++i)
            {
                mData[i] = 0;
            }
        }
    }

    vector::vector(size_type size, int value) : mSize(size), mData(nullptr)
    {
        if (mSize != 0)
        {
            mData = new int[mSize];

            for (size_type i = 0; i < mSize; ++i)
            {
                mData[i] = value;
            }
        }
    }

    vector::~vector()
    {
        delete[] mData;
    }
}
