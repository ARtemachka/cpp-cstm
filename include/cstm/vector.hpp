#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <stdexcept>

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

        vector(std::initializer_list<T> init) : mSize(0), mData(nullptr)
        {
            if (init.size() != 0)
            {
                mData = new int[init.size()];

                for (auto it = init.begin(); it != init.end(); ++it)
                {
                    mData[std::distance(init.begin(), it)] = *it;
                }

                mSize = init.size();
            }
        }

        vector(const vector& other) : mSize(0), mData(nullptr)
        {
            if (!other.empty())
            {
                mData = new int[other.size()];

                for (size_type i = 0; i < other.size(); ++i)
                {
                    mData[i] = other[i];
                }

                mSize = other.size();
            }
        }

        ~vector()
        {
            delete[] mData;
        }

        reference at(size_type pos)
        {
            if (pos >= mSize)
            {
                throw std::out_of_range("");
            }

            return mData[pos];
        }

        const_reference at(size_type pos) const
        {
            if (pos >= mSize)
            {
                throw std::out_of_range("");
            }

            return mData[pos];
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

        bool empty() const noexcept
        {
            return mSize == 0;
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

        reference operator[](size_type pos)
        {
            return mData[pos];
        }

        const_reference operator[](size_type pos) const
        {
            return mData[pos];
        }

    private:
        size_type mSize;
        T* mData;
    };
}
