//
// elnormous/math
//

#ifndef MATH_VECTOR
#define MATH_VECTOR

#include <array>
#include <type_traits>

namespace math
{
    template <typename T, std::size_t N> class Vector final
    {
    public:
#if defined(__SSE__)
        alignas(N == 4 ? 4 * sizeof(T) : alignof(T))
#endif
        std::array<T, N> v{};

        constexpr Vector() noexcept {}

        template <typename ...A>
        explicit constexpr Vector(A... args) noexcept:
            v{static_cast<T>(args)...}
        {
        }

        auto& operator[](std::size_t index) noexcept { return v[index]; }
        constexpr auto operator[](std::size_t index) const noexcept { return v[index]; }

        template <std::size_t X = N, std::enable_if_t<(X >= 1)>* = nullptr>
        auto& x() noexcept { return v[0]; }

        template <std::size_t X = N, std::enable_if_t<(X >= 1)>* = nullptr>
        constexpr auto x() const noexcept { return v[0]; }

        template <std::size_t X = N, std::enable_if_t<(X >= 2)>* = nullptr>
        auto& y() noexcept { return v[1]; }

        template <std::size_t X = N, std::enable_if_t<(X >= 2)>* = nullptr>
        constexpr auto y() const noexcept { return v[1]; }

        template <std::size_t X = N, std::enable_if_t<(X >= 3)>* = nullptr>
        auto& z() noexcept { return v[2]; }

        template <std::size_t X = N, std::enable_if_t<(X >= 3)>* = nullptr>
        constexpr auto z() const noexcept { return v[2]; }

        template <std::size_t X = N, std::enable_if_t<(X >= 4)>* = nullptr>
        auto& w() noexcept { return v[3]; }

        template <std::size_t X = N, std::enable_if_t<(X >= 4)>* = nullptr>
        constexpr auto w() const noexcept { return v[3]; }
    };
}

#endif
