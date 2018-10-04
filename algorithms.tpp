#include <unordered_set>

namespace ktl
{

template<class InputIt, class T>
InputIt
find(InputIt first, InputIt second, const T& val)
{
    for (; first != second; ++first)
        {
            if (*first == val)
                break;
        }

    return first;
}

template<class InputIt, class UnaryPredicate>
InputIt
findIf(InputIt first, InputIt second, UnaryPredicate p)
{
    for (; first != second; ++first)
        {
            if (p(*first))
                break;
        }

    return first;
}

template<class InputIt, class UnaryPredicate>
InputIt
findIfNot(InputIt first, InputIt second, UnaryPredicate p)
{
    for (; first != second; ++first)
        {
            if (!p(*first))
                break;
        }

    return first;
}

template<class BidirIt, class T>
BidirIt
findLast(BidirIt first, BidirIt last, const T& val)
{
    --last;
    --first;
    for (; last != first; --last)
        if (*last == val)
            break;
    return last;
}

template<class InputIt, class UnaryPredicate>
bool
all_of(InputIt first, InputIt second, UnaryPredicate p)
{
    if (find_if_not(first, second, p) != second)
        return false;
    return true;
}

template<class InputIt, class UnaryPredicate>
bool
any_of(InputIt first, InputIt second, UnaryPredicate p)
{
    if (find_if(first, second, p) == second)
        return false;
    return true;
}

template<class InputIt, class UnaryPredicate>
bool
none_of(InputIt first, InputIt second, UnaryPredicate p)
{
    if (find_if(first, second, p) != second)
        return false;
    return true;
}

template<class InputIt, class UnaryPredicate>
UnaryPredicate
forEach(InputIt first, InputIt second, UnaryPredicate p)
{
    for (; first != second; ++first)
        p(*first);
    return p;
}

template<class ForwardIt1, class ForwardIt2, class BinaryPredicate>
ForwardIt1
findFirstOf(ForwardIt1 first,
            ForwardIt1 second,
            ForwardIt2 first2,
            ForwardIt2 second2,
            BinaryPredicate p)
{
    for (; first != second; ++first)
        for (ForwardIt2 i = first2; i != second2; ++i)
            if (p(*first, *i))
                return first;

    return second;
}

template<class ForwardIt1, class ForwardIt2, class BinaryPredicate>
ForwardIt1
findFirstOf2(ForwardIt1 first,
             ForwardIt1 second,
             ForwardIt2 first2,
             ForwardIt2 second2,
             BinaryPredicate p)
{
    using v_t = typename ForwardIt2::value_type;
    std::unordered_set<v_t, std::hash<v_t>, BinaryPredicate> set(
      10, std::hash<v_t>(), p);
    for (; first2 != second2; ++first2)
        set.insert(*first2);

    for (; first != second; ++first)
        if (set.find(*first) != set.end())
            break;

    return first;
}

template<class InputIt, class OutputIt>
OutputIt
copy(InputIt first, InputIt last, OutputIt out)
{
    for (; first != last; ++first)
        *out++ = *first;
    return out;
}

template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt
copyIf(InputIt first, InputIt last, OutputIt out, UnaryPredicate p)
{
    for (; first != last; ++first)
        if (p(*first))
            *out++ = *first;
    return out;
}

template<class InputIt, class OutputIt>
OutputIt
move(InputIt first, InputIt last, OutputIt out)
{
    for (; first != last; ++first)
        *out++ = std::move(*first);
    return out;
}

template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt
moveIf(InputIt first, InputIt last, OutputIt out, UnaryPredicate p)
{
    for (; first != last; ++first)
        if (p(*first))
            *out++ = std::move(*first);
    return out;
}

template<class ForwardIt, class T>
ForwardIt
remove(ForwardIt first, ForwardIt last, const T& value)
{
    first = ktl::find(first, last, value);
    for (ForwardIt i = first; i != last; ++i)
        if (!(*i == value))
            *first++ = std::move(*i);
    return first;
}

template<class BidirIt, class T>
BidirIt
remove2(BidirIt first, BidirIt last, const T& value)
{
    BidirIt ffirst = first;
    while (*--last == value)
        ;
    first = ktl::find(first, last, value);
    while (first <= last)
        {
            if (*first == value)
                {
                    *first = std::move(*last--);
                    while (last > ffirst && *last == value)
                        --last;
                }
            ++first;
        }
    return ++last;
}

} // namespace ktl
