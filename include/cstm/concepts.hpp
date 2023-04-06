#pragma once

#include <concepts>

namespace cstm
{
    template <typename T>
    concept destructible_non_ref = std::destructible<T> && !std::is_reference_v<T>;
}
