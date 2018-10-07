#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <utility>

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

template<class RanIt, class T>
RanIt
remove2(RanIt first, RanIt last, const T& value)
{
    RanIt ffirst = first;
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

template<class T>
void
swap(T& lhs, T& rhs)
{
    T tmp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(tmp);
}

template<class BidirIt>
void
reverse(BidirIt first, BidirIt last)
{
    while (first != last && first != --last)
        swap(*first++, *last);
}

template<class BidirIt, class OutputIt>
OutputIt
reverseCopy(BidirIt first, BidirIt last, OutputIt out)
{
    while (last-- != first)
        *out++ = *last;
    return out;
}

template<class ForwardIt>
void
rotate(ForwardIt first, ForwardIt mid, ForwardIt last)
{
    ForwardIt next = mid;
    while (!(first == next))
        {
            swap(*first++, *next++);
            if (next == last)
                next = mid;
            if (first == mid)
                mid = next;
        }
}

template<class ForwardIt>
ForwardIt
unique(ForwardIt first, ForwardIt last)
{
    for (ForwardIt i = first; !(i == last);)
        {
            ForwardIt prevFirst = first;
            if (!(first == i))
                *first = std::move(*i);
            ++first;
            ++i;
            while (!(i == last) && *prevFirst == *i)
                ++i;
        }
    return first;
}

template<class ForwardIt, class OutputIt>
OutputIt
uniqueCopy(ForwardIt first, ForwardIt last, OutputIt out)
{
    for (ForwardIt i = first; !(i == last);)
        {
            *out++ = *i++;
            while (!(i == last) && *first == *i)
                ++i;
            first = i;
        }
    return out;
}

template<class RanIt>
void
shuffle(RanIt first, RanIt second)
{
    srand(time(0));
    size_t n = std::distance(first, second);
    for (size_t i = n - 1; i > 0; --i)
        {
            size_t j = rand() % (i + 1);
            swap(first[j], first[i]);
        }
}

template<class InputIt, class UnaryPredicate>
bool
isPartitioned(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first)
        if (!p(*first))
            break;

    for (; first != last; ++first)
        if (p(*first))
            return false;
    return true;
}

template<class ForwardIt, class UnaryPredicate>
ForwardIt
partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = findIfNot(first, last, p);

    for (ForwardIt i = first; i != last; ++i)
        {
            if (p(*i))
                swap(*first++, *i);
        }
    return first;
}

template<class ForwardIt, class T>
ForwardIt
lowerBound(ForwardIt first, ForwardIt last, const T& val)
{
    size_t count = std::distance(first, last);
    ForwardIt i;
    while (count > 0)
        {
            i = first;
            std::advance(i, count / 2);
            if (*i < val)
                {
                    first = ++i;
                    count -= count / 2 + 1;
                }
            else
                count = count / 2;
        }
    return first;
}

template<class ForwardIt, class T>
ForwardIt
upperBound(ForwardIt first, ForwardIt last, const T& val)
{
    size_t count = std::distance(first, last);
    ForwardIt i;
    while (count > 0)
        {
            i = first;
            std::advance(i, count / 2);
            if (*i <= val)
                {
                    first = ++i;
                    count -= count / 2 + 1;
                }
            else
                count = count / 2;
        }
    return first;
}

} // namespace ktl
