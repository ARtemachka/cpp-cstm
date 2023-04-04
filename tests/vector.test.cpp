#include "cstm/vector.hpp"
#include <gtest/gtest.h>

#include <algorithm>

TEST(VectorTest, Construction)
{
    {
        cstm::vector<int> v;

        EXPECT_TRUE(v.size() == 0);
        EXPECT_TRUE(v.data() == nullptr);
        EXPECT_TRUE(v.begin() == v.end());
        EXPECT_TRUE(v.cbegin() == v.cend());
    }

    {
        cstm::vector<int> v(0);

        EXPECT_TRUE(v.size() == 0);
        EXPECT_TRUE(v.data() == nullptr);
        EXPECT_TRUE(v.begin() == v.end());
        EXPECT_TRUE(v.cbegin() == v.cend());
    }

    {
        cstm::vector<int> v(10);

        EXPECT_TRUE(v.size() == 10);
        EXPECT_TRUE(v.data() != nullptr);
        EXPECT_TRUE(v.begin() != v.end());
        EXPECT_TRUE(v.cbegin() != v.cend());
        EXPECT_TRUE(*v.begin() == 0);
        EXPECT_TRUE(*v.cbegin() == 0);
        EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 0; }));
    }

    {
        cstm::vector<int> v(0, 5);

        EXPECT_TRUE(v.size() == 0);
        EXPECT_TRUE(v.data() == nullptr);
        EXPECT_TRUE(v.begin() == v.end());
        EXPECT_TRUE(v.cbegin() == v.cend());
    }

    {
        cstm::vector<int> v(10, 5);

        EXPECT_TRUE(v.size() == 10);
        EXPECT_TRUE(v.data() != nullptr);
        EXPECT_TRUE(v.begin() != v.end());
        EXPECT_TRUE(v.cbegin() != v.cend());
        EXPECT_TRUE(*v.begin() == 5);
        EXPECT_TRUE(*v.cbegin() == 5);
        EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 5; }));
    }
}
