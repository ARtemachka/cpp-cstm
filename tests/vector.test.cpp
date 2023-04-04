#include "cstm/vector.hpp"
#include <gtest/gtest.h>

#include <algorithm>
#include <stdexcept>

TEST(VectorTest, Construction)
{
    {
        cstm::vector<int> v;

        EXPECT_TRUE(v.empty());
        EXPECT_TRUE(v.data() == nullptr);
        EXPECT_TRUE(v.begin() == v.end());
        EXPECT_TRUE(v.cbegin() == v.cend());

        const cstm::vector<int> cv;

        EXPECT_TRUE(cv.empty());
        EXPECT_TRUE(cv.data() == nullptr);
        EXPECT_TRUE(cv.cbegin() == v.cend());
    }

    {
        cstm::vector<int> v(0);

        EXPECT_TRUE(v.empty());
        EXPECT_TRUE(v.data() == nullptr);
        EXPECT_TRUE(v.begin() == v.end());
        EXPECT_TRUE(v.cbegin() == v.cend());
    }

    {
        cstm::vector<int> v(10);

        EXPECT_TRUE(v.empty() == false);
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

        EXPECT_TRUE(v.empty());
        EXPECT_TRUE(v.size() == 0);
        EXPECT_TRUE(v.data() == nullptr);
        EXPECT_TRUE(v.begin() == v.end());
        EXPECT_TRUE(v.cbegin() == v.cend());
    }

    {
        cstm::vector<int> v(10, 5);

        EXPECT_TRUE(v.empty() == false);
        EXPECT_TRUE(v.size() == 10);
        EXPECT_TRUE(v.data() != nullptr);
        EXPECT_TRUE(v.begin() != v.end());
        EXPECT_TRUE(v.cbegin() != v.cend());
        EXPECT_TRUE(*v.begin() == 5);
        EXPECT_TRUE(*v.cbegin() == 5);
        EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 5; }));
    }

    {
        cstm::vector<int> v({});

        EXPECT_TRUE(v.empty());
        EXPECT_TRUE(v.data() == nullptr);
        EXPECT_TRUE(v.begin() == v.end());
        EXPECT_TRUE(v.cbegin() == v.cend());
    }

    {
        cstm::vector<int> v({ 1, 2, 3, 4, 5 });

        EXPECT_TRUE(v.empty() == false);
        EXPECT_TRUE(v.size() == 5);
        EXPECT_TRUE(v.data() != nullptr);
        EXPECT_TRUE(v.begin() != v.end());
        EXPECT_TRUE(v.cbegin() != v.cend());
        EXPECT_TRUE(*v.begin() == 1);
        EXPECT_TRUE(*v.cbegin() == 1);
    }
}

TEST(VectorTest, ElementAccess)
{
    {
        cstm::vector<int> v;

        EXPECT_THROW(v.at(0), std::out_of_range);
    }

    {
        cstm::vector<int> v(1);

        EXPECT_NO_THROW(v.at(0));
        EXPECT_EQ(v[0], 0);
        EXPECT_THROW(v.at(1), std::out_of_range);
    }

    {
        cstm::vector<int> v({ 1, 2, 3, 4, 5});

        for (cstm::vector<int>::size_type i = 0; i < v.size(); ++i)
        {
            EXPECT_NO_THROW(v.at(i));
            EXPECT_EQ(v[i], i + 1);
        }

        EXPECT_THROW(v.at(5), std::out_of_range);
    }
}
