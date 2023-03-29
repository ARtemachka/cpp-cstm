#include "vector.hh"
#include <algorithm>

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
            std::fill(mData, mData + mSize, 0);
        }
    }

    vector::vector(size_type size, int value) : mSize(size), mData(nullptr)
    {
        if (mSize != 0)
        {
            mData = new int[mSize];
            std::fill(mData, mData + mSize, value);
        }
    }

    vector::~vector()
    {
        delete[] mData;
    }
}
