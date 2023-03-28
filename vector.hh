#pragma once

#include <cstddef>

namespace cstm
{
    class vector
    {
    public:
        using size_type = std::size_t;

        vector();
        explicit vector(size_type size);
        vector(size_type size, int value);

    private:
        size_type mSize;
        int* mData;
    };
}
