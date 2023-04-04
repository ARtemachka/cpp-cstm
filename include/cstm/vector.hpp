#pragma once

#include <algorithm>
#include <cstddef>

namespace cstm
{
    template <class T>
    class vector
    {
    public:
        using value_type = T;
        using size_type = std::size_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = T*;
        using const_iterator = const T*;

        vector() : mSize(0), mData(nullptr)
        {

        }

        explicit vector(size_type size) : mSize(size), mData(nullptr)
        {
            if (mSize != 0)
            {
                mData = new T[mSize];
                std::fill(mData, mData + mSize, 0);
            }
        }

        vector(size_type size, const T& value) : mSize(size), mData(nullptr)
        {
            if (mSize != 0)
            {
                mData = new T[mSize];
                std::fill(mData, mData + mSize, value);
            }
        }

        ~vector()
        {
            delete[] mData;
        }

        iterator begin() noexcept
        {
            return mData;
        }

        const_iterator cbegin() const noexcept
        {
            return mData;
        }

        T* data() noexcept
        {
            return mData;
        }

        const T* data() const noexcept
        {
            return mData;
        }

        iterator end() noexcept
        {
            return mData + mSize;
        }

        const_iterator cend() const noexcept
        {
            return mData + mSize;
        }
        
        size_type size() const noexcept
        {
            return mSize;
        }

    private:
        size_type mSize;
        T* mData;
    };
}
