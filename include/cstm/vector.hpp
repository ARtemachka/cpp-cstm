#pragma once

#include <algorithm>
#include <cstddef>

namespace cstm
{
    class vector
    {
    public:
        using size_type = std::size_t;

        vector() : mSize(0), mData(nullptr)
        {

        }

        explicit vector(size_type size) : mSize(size), mData(nullptr)
        {
            if (mSize != 0)
            {
                mData = new int[mSize];
                std::fill(mData, mData + mSize, 0);
            }
        }

        vector(size_type size, int value) : mSize(size), mData(nullptr)
        {
            if (mSize != 0)
            {
                mData = new int[mSize];
                std::fill(mData, mData + mSize, value);
            }
        }

        ~vector()
        {
            delete[] mData;
        }

    private:
        size_type mSize;
        int* mData;
    };
}
