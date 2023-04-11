#pragma once

#include "cstm/concepts.hpp"

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <stdexcept>

namespace cstm
{
    template <typename T>
        requires cstm::destructible_non_ref<T>
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
                mData = new T[init.size()];

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
                mData = new T[other.mSize];

                for (size_type i = 0; i < other.mSize; ++i)
                {
                    mData[i] = other[i];
                }

                mSize = other.mSize;
            }
        }

        vector(vector&& other) noexcept : mSize(other.mSize), mData(other.mData)
        {
            other.mSize = 0;
            other.mData = nullptr;
        }

        // TODO: copy and swap
        vector& operator=(const vector& other)
        {
            if (this == &other)
            {
                return *this;
            }

            mSize = 0;
            delete[] mData;
            mData = nullptr;

            if (!other.empty())
            {
                mData = new T[other.size()];

                for (size_type i = 0; i < other.size(); ++i)
                {
                    mData[i] = other[i];
                }

                mSize = other.size();
            }

            return *this;
        }

        vector& operator=(vector&& other) noexcept
        {
            if (this == &other)
            {
                return *this;
            }

            delete[] mData;
            mSize = other.mSize;
            mData = other.mData;

            other.mSize = 0;
            other.mData = nullptr;

            return *this;
        }

        ~vector()
        {
            delete[] mData;
        }

        void assign(size_type count, const T& value)
        {
            mSize = 0;
            delete[] mData;
            mData = nullptr;

            if (count != 0)
            {
                mData = new T[count];

                for (size_type i = 0; i < count; ++i)
                {
                    mData[i] = value;
                }

                mSize = count;
            }
        }

        void assign(std::initializer_list<T> ilist)
        {
            mSize = 0;
            delete[] mData;
            mData = nullptr;

            if (ilist.size() != 0)
            {
                mData = new T[ilist.size()];

                for (auto it = ilist.begin(); it != ilist.end(); ++it)
                {
                    mData[std::distance(ilist.begin(), it)] = *it;
                }

                mSize = ilist.size();
            }
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

        void clear() noexcept
        {
            delete[] mData;
            mData = nullptr;
            mSize = 0;
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
