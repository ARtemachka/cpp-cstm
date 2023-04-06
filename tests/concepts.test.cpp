#include "cstm/concepts.hpp"
#include <gtest/gtest.h>

template <typename T>
    requires cstm::destructible_non_ref<T>
struct S
{

};

template <typename T>
constexpr bool allowed = requires {
    S<T>();
};

TEST(ConceptsTest, DestructibleNonRef)
{
    struct WithDtor
    {

    };

    struct WithoutDtor
    {
        ~WithoutDtor() = delete;
    };

    // Note: these are compile time tests
    static_assert(allowed<int>);
    static_assert(allowed<int*>);
    static_assert(allowed<WithDtor>);
    static_assert(allowed<int[]> == false);
    static_assert(allowed<int&> == false);
    static_assert(allowed<void> == false);
    static_assert(allowed<WithoutDtor> == false);
}