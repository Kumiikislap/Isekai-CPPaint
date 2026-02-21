#include <algorithm>
#include <concepts>
#include <ranges>

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/variant.hpp>

template <typename TGodotArr = godot::PackedByteArray, typename... T>
    requires(std::convertible_to<T, godot::Variant> && ...)
class gdvec : public TGodotArr
{
public:
    using value_type = godot::Variant;
    using iterator_type = typename TGodotArr::Iterator;
    using const_iterator = typename TGodotArr::ConstIterator;
    using difference_type = std::ptrdiff_t;
    using TGodotArr::TGodotArr;
    using TGodotArr::operator=;
    using TGodotArr::insert;
    using TGodotArr::push_back;

    constexpr gdvec(gdvec&& other) noexcept
        : m_data{ std::move(other.m_data) }
        , m_size{ std::move(other.m_data) }
    {
    }

    constexpr gdvec(const gdvec& other)
        : m_data{ std::copy(other.m_data) }
        , m_size{ std::copy(other.m_data) }
    {
    }

    constexpr explicit gdvec(T&&... vals)
        : m_size{ sizeof...(T) }
    {
        for (auto&& v : { godot::Variant(std::forward<T>(vals))... })
            m_data.push_back(std::move(v));
    }

    constexpr explicit gdvec(std::array<godot::Variant, sizeof...(T)> vals)
        : m_size{ sizeof...(T) }
    {
        std::ranges::move(godot::Variant(vals), *this);
    }

    template <std::ranges::range R>
    constexpr gdvec(const R& range)
    {
        std::ranges::copy(std::forward<R>(range), std::back_inserter(m_data));
    }

    template <std::ranges::range R>
        requires((std::convertible_to<std::views::all_t<R>, T> && ...) &&
                 std::is_rvalue_reference_v<R>)
    constexpr gdvec(R&& range)
    {
        std::ranges::move(std::forward<R>(range), std::back_inserter(m_data));
    }

    template <typename To = TGodotArr>
        requires std::convertible_to<TGodotArr, To>
    constexpr auto data() -> To
    {
        return godot::Object::cast_to<To>(m_data);
    }

    constexpr auto operator[](this auto self, std::size_t idx)
    {
        return self.m_data[idx];
    }

    constexpr auto begin(this auto&& self)
    {
        godot::PackedByteArray arr;

        return self.m_data.begin();
    }

    constexpr auto end(this auto&& self)
    {
        return self.m_data.end();
    }

    constexpr std::size_t size() const
    {
#ifndef NDEBUG
        m_size = m_data.size();
#endif
        return m_size;
    }

private:
    TGodotArr m_data{};

#ifndef NDEBUG
    mutable std::size_t m_size{ 0 };
#endif
};
