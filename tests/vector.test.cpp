#include "cstm/vector.hpp"
#include "gtest/gtest.h"
#include <algorithm>
#include <ranges>
#include <stdexcept>

namespace
{
    struct S
    {
    };
} // namespace

TEST(VectorTest, AssignmentOperator)
{
    {
        {
            cstm::vector<int> v1;
            cstm::vector<int> v2{ 4, 4, 4, 4 };
            v1 = v2;

            EXPECT_FALSE(v1.empty());
            EXPECT_FALSE(v2.empty());
            EXPECT_EQ(v1.size(), v2.size());
            EXPECT_TRUE(std::ranges::equal(v1, v2));
        }

        {
            cstm::vector<int> v{ 4, 4, 4, 4 };
            v = v;

            EXPECT_FALSE(v.empty());
            EXPECT_EQ(v.size(), 4);
            EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 4; }));
        }

        {
            cstm::vector<int> v1;
            cstm::vector<int> v2;
            v1 = v2;

            EXPECT_TRUE(v1.empty());
            EXPECT_TRUE(v2.empty());
            EXPECT_EQ(v1.data(), nullptr);
            EXPECT_EQ(v2.data(), nullptr);
        }
    }

    {
        {
            cstm::vector<int> v1;
            cstm::vector<int> v2{ 4, 4, 4, 4 };

            int* data = v2.data();
            v1 = std::move(v2);

            EXPECT_FALSE(v1.empty());
            EXPECT_TRUE(v2.empty());
            EXPECT_EQ(v1.size(), 4);
            EXPECT_EQ(v1.data(), data);
            EXPECT_TRUE(std::all_of(v1.cbegin(), v1.cend(), [](int n) { return n == 4; }));
        }

        {
            cstm::vector<int> v{ 4, 4, 4, 4 };
            v = std::move(v);

            EXPECT_FALSE(v.empty());
            EXPECT_EQ(v.size(), 4);
            EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 4; }));
        }
    }

    {
        {
            cstm::vector<int> v;
            v = { 5, 5, 5, 5, 5 };

            EXPECT_FALSE(v.empty());
            EXPECT_EQ(v.size(), 5);
            EXPECT_NE(v.data(), nullptr);
            EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 5; }));
        }

        {
            cstm::vector<int> v;
            v = {};

            EXPECT_TRUE(v.empty());
            EXPECT_EQ(v.data(), nullptr);
        }
    }
}

TEST(VectorTest, Construction)
{
    {
        cstm::vector<int> v;

        EXPECT_TRUE(v.empty());
        EXPECT_EQ(v.data(), nullptr);
        EXPECT_EQ(v.begin(), v.end());
        EXPECT_EQ(v.cbegin(), v.cend());

        const cstm::vector<int> cv;

        EXPECT_TRUE(cv.empty());
        EXPECT_EQ(cv.data(), nullptr);
        EXPECT_EQ(cv.cbegin(), v.cend());
    }

    {
        cstm::vector<int> v(0);

        EXPECT_TRUE(v.empty());
        EXPECT_EQ(v.data(), nullptr);
        EXPECT_EQ(v.begin(), v.end());
        EXPECT_EQ(v.cbegin(), v.cend());
    }

    {
        cstm::vector<int> v(10);

        EXPECT_FALSE(v.empty());
        EXPECT_EQ(v.size(), 10);
        EXPECT_NE(v.data(), nullptr);
        EXPECT_NE(v.begin(), v.end());
        EXPECT_NE(v.cbegin(), v.cend());
        EXPECT_EQ(*v.begin(), 0);
        EXPECT_EQ(*v.cbegin(), 0);
        EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 0; }));
    }

    {
        cstm::vector<int> v(0, 5);

        EXPECT_TRUE(v.empty());
        EXPECT_EQ(v.size(), 0);
        EXPECT_EQ(v.data(), nullptr);
        EXPECT_EQ(v.begin(), v.end());
        EXPECT_EQ(v.cbegin(), v.cend());
    }

    {
        cstm::vector<int> v(10, 5);

        EXPECT_FALSE(v.empty());
        EXPECT_EQ(v.size(), 10);
        EXPECT_NE(v.data(), nullptr);
        EXPECT_NE(v.begin(), v.end());
        EXPECT_NE(v.cbegin(), v.cend());
        EXPECT_EQ(*v.begin(), 5);
        EXPECT_EQ(*v.cbegin(), 5);
        EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 5; }));
    }

    {
        cstm::vector<int> v({});

        EXPECT_TRUE(v.empty());
        EXPECT_EQ(v.data(), nullptr);
        EXPECT_EQ(v.begin(), v.end());
        EXPECT_EQ(v.cbegin(), v.cend());
    }

    {
        cstm::vector<int> v{ 1, 2, 3, 4, 5 };

        EXPECT_FALSE(v.empty());
        EXPECT_EQ(v.size(), 5);
        EXPECT_NE(v.data(), nullptr);
        EXPECT_NE(v.begin(), v.end());
        EXPECT_NE(v.cbegin(), v.cend());
        EXPECT_EQ(*v.begin(), 1);
        EXPECT_EQ(*v.cbegin(), 1);
    }

    {
        cstm::vector<int> v1;
        cstm::vector<int> v2(v1);

        EXPECT_TRUE(v2.empty());
        EXPECT_EQ(v2.data(), nullptr);
        EXPECT_EQ(v2.begin(), v2.end());
        EXPECT_EQ(v2.cbegin(), v2.cend());
    }

    {
        cstm::vector<int> v1{ 1, 2, 3, 4, 5 };
        cstm::vector<int> v2(v1);

        EXPECT_FALSE(v2.empty());
        EXPECT_EQ(v1.size(), v2.size());
        EXPECT_NE(v2.data(), nullptr);
        EXPECT_NE(v2.begin(), v2.end());
        EXPECT_NE(v2.cbegin(), v2.cend());
        EXPECT_TRUE(std::ranges::equal(v1, v2));
    }

    {
        cstm::vector<int> v1{ 1, 2, 3, 4, 5 };
        cstm::vector<int> v2(std::move(v1));

        EXPECT_TRUE(v1.empty());
        EXPECT_EQ(v1.data(), nullptr);
        EXPECT_EQ(v1.begin(), v1.end());
        EXPECT_EQ(v1.cbegin(), v1.cend());

        EXPECT_FALSE(v2.empty());
        EXPECT_EQ(v2.size(), 5);
        EXPECT_NE(v2.data(), nullptr);
        EXPECT_NE(v2.begin(), v2.end());
        EXPECT_NE(v2.cbegin(), v2.cend());
    }
}

TEST(VectorTest, ElementAccess)
{
    {
        cstm::vector<int> v;

        EXPECT_THROW(v.at(0), std::out_of_range);

        const cstm::vector<int> cv;

        EXPECT_THROW(v.at(0), std::out_of_range);
    }

    {
        cstm::vector<int> v(1);

        EXPECT_NO_THROW(v.at(0));
        EXPECT_EQ(v[0], 0);
        EXPECT_EQ(v.front(), 0);
        EXPECT_EQ(v.back(), 0);
        EXPECT_THROW(v.at(1), std::out_of_range);

        const cstm::vector<int> cv(1);

        EXPECT_NO_THROW(cv.at(0));
        EXPECT_EQ(cv[0], 0);
        EXPECT_EQ(cv.front(), 0);
        EXPECT_EQ(cv.back(), 0);
        EXPECT_THROW(cv.at(1), std::out_of_range);
    }

    {
        {
            cstm::vector<int> v{ 1, 2, 3, 4, 5 };

            for (cstm::vector<int>::size_type i = 0; i < v.size(); ++i)
            {
                EXPECT_NO_THROW(v.at(i));
                EXPECT_EQ(v[i], i + 1);
            }

            EXPECT_THROW(v.at(5), std::out_of_range);
            EXPECT_EQ(v.front(), 1);
            EXPECT_EQ(v.back(), 5);
        }

        {
            const cstm::vector<int> cv{ 1, 2, 3, 4, 5 };

            for (cstm::vector<int>::size_type i = 0; i < cv.size(); ++i)
            {
                EXPECT_NO_THROW(cv.at(i));
                EXPECT_EQ(cv[i], i + 1);
            }

            EXPECT_THROW(cv.at(5), std::out_of_range);
            EXPECT_EQ(cv.front(), 1);
            EXPECT_EQ(cv.back(), 5);
        }
    }
}

TEST(VectorTest, Assign)
{
    {
        cstm::vector<int> v;
        v.assign(5, 10);

        EXPECT_FALSE(v.empty());
        EXPECT_EQ(v.size(), 5);
        EXPECT_NE(v.data(), nullptr);
        EXPECT_NE(v.begin(), v.end());
        EXPECT_NE(v.cbegin(), v.cend());
        EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 10; }));
    }

    {
        cstm::vector<int> v;
        v.assign(0, 10);

        EXPECT_TRUE(v.empty());
        EXPECT_EQ(v.data(), nullptr);
        EXPECT_EQ(v.begin(), v.end());
        EXPECT_EQ(v.cbegin(), v.cend());
    }

    {
        cstm::vector<int> v;
        v.assign({ 10, 10, 10, 10, 10 });

        EXPECT_FALSE(v.empty());
        EXPECT_EQ(v.size(), 5);
        EXPECT_NE(v.data(), nullptr);
        EXPECT_NE(v.begin(), v.end());
        EXPECT_NE(v.cbegin(), v.cend());
        EXPECT_TRUE(std::all_of(v.cbegin(), v.cend(), [](int n) { return n == 10; }));
    }

    {
        cstm::vector<int> v;
        v.assign({});

        EXPECT_TRUE(v.empty());
        EXPECT_EQ(v.data(), nullptr);
        EXPECT_EQ(v.begin(), v.end());
        EXPECT_EQ(v.cbegin(), v.cend());
    }
}

TEST(VectorTest, Clear)
{
    cstm::vector<int> v{ 1, 2, 3, 4, 5 };

    EXPECT_FALSE(v.empty());
    EXPECT_EQ(v.size(), 5);
    EXPECT_NE(v.data(), nullptr);
    EXPECT_NE(v.begin(), v.end());
    EXPECT_NE(v.cbegin(), v.cend());

    v.clear();

    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.data(), nullptr);
    EXPECT_EQ(v.begin(), v.end());
    EXPECT_EQ(v.cbegin(), v.cend());
}

TEST(VectorTest, PushBack)
{
    {
        {
            cstm::vector<S> v;
            S s;
            v.push_back(s);

            EXPECT_FALSE(v.empty());
            EXPECT_EQ(v.size(), 1);
            EXPECT_NO_THROW(v.at(0));
        }

        {
            cstm::vector<S> v{ S(), S(), S(), S() };
            S s;
            v.push_back(s);

            EXPECT_FALSE(v.empty());
            EXPECT_EQ(v.size(), 5);
            EXPECT_NO_THROW(v.at(4));
        }
    }

    {
        {
            cstm::vector<S> v;
            S s;
            v.push_back(std::move(s));

            EXPECT_FALSE(v.empty());
            EXPECT_EQ(v.size(), 1);
            EXPECT_NO_THROW(v.at(0));
        }

        {
            cstm::vector<S> v{ S(), S(), S(), S() };
            S s;
            v.push_back(std::move(s));

            EXPECT_FALSE(v.empty());
            EXPECT_EQ(v.size(), 5);
            EXPECT_NO_THROW(v.at(4));
        }
    }
}

TEST(VectorTest, Resize)
{
    {
        cstm::vector<int> v{ 1, 2, 3, 4, 5 };
        v.resize(3);

        EXPECT_FALSE(v.empty());
        EXPECT_EQ(v.size(), 3);

        for (int i = 0; i < 3; ++i)
        {
            EXPECT_EQ(v.at(i), i + 1);
        }
    }

    {
        cstm::vector<int> v{ 1, 2, 3, 4, 5 };
        v.resize(10, 5);

        EXPECT_FALSE(v.empty());
        EXPECT_EQ(v.size(), 10);

        for (int i = 0; i < 5; ++i)
        {
            EXPECT_EQ(v.at(i), i + 1);
        }

        for (int i = 5; i < 10; ++i)
        {
            EXPECT_EQ(v.at(i), 5);
        }
    }

    {
        cstm::vector<int> v{ 1, 2, 3, 4, 5 };
        v.resize(0);

        EXPECT_TRUE(v.empty());
        EXPECT_EQ(v.size(), 0);
    }
}

TEST(VectorTest, Swap)
{
    {
        cstm::vector<int> v1{ 1, 2, 3, 4, 5 };
        cstm::vector<int> v2{ 1, 2, 3 };
        v1.swap(v2);

        EXPECT_EQ(v1.size(), 3);
        EXPECT_EQ(v2.size(), 5);

        for (int i = 0; i < 3; ++i)
        {
            EXPECT_EQ(v1.at(i), i + 1);
        }

        for (int i = 0; i < 5; ++i)
        {
            EXPECT_EQ(v2.at(i), i + 1);
        }
    }

    {
        cstm::vector<int> v1{ 1, 2, 3, 4, 5 };
        cstm::vector<int> v2{ 1, 2, 3 };
        cstm::swap(v1, v2);

        EXPECT_EQ(v1.size(), 3);
        EXPECT_EQ(v2.size(), 5);

        for (int i = 0; i < 3; ++i)
        {
            EXPECT_EQ(v1.at(i), i + 1);
        }

        for (int i = 0; i < 5; ++i)
        {
            EXPECT_EQ(v2.at(i), i + 1);
        }
    }
}
