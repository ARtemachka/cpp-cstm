#include "cstm/vector.hpp"
#include <gtest/gtest.h>

#include <algorithm>
#include <limits>

TEST(VectorTest, Construction)
{
    {
        cstm::vector v;

        EXPECT_TRUE(v.size() == 0);
        EXPECT_TRUE(v.data() == nullptr);
    }

    {
        cstm::vector v(0);

        EXPECT_TRUE(v.size() == 0);
        EXPECT_TRUE(v.data() == nullptr);
    }

    {
        cstm::vector v(10);

        EXPECT_TRUE(v.size() == 10);
        EXPECT_TRUE(v.data() != nullptr);
        EXPECT_TRUE(std::all_of(v.data(), v.data() + v.size(), [](int n) { return n == 0; }));
    }

    {
        cstm::vector v(10, 5);

        EXPECT_TRUE(v.size() == 10);
        EXPECT_TRUE(v.data() != nullptr);
        EXPECT_TRUE(std::all_of(v.data(), v.data() + v.size(), [](int n) { return n == 5; }));
    }
}
