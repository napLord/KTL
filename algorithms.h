#pragma once

namespace ktl
{

template<class InputIt, class T>
InputIt
find(InputIt first, InputIt second, const T& val);

template<class InputIt, class UnaryPredicate>
InputIt
findIf(InputIt first, InputIt second, UnaryPredicate p);

template<class InputIt, class UnaryPredicate>
InputIt
findIfNot(InputIt first, InputIt second, UnaryPredicate p);

template<class BidirIt, class T>
BidirIt
findLast(BidirIt first, BidirIt last, const T& val);

template<class InputIt, class UnaryPredicate>
bool
allOf(InputIt first, InputIt second, UnaryPredicate p);

template<class InputIt, class UnaryPredicate>
bool
anyOf(InputIt first, InputIt second, UnaryPredicate p);

template<class InputIt, class UnaryPredicate>
bool
noneOf(InputIt first, InputIt second, UnaryPredicate p);

template<class InputIt, class UnaryPredicate>
UnaryPredicate
forEach(InputIt first, InputIt second, UnaryPredicate p);

template<class ForwardIt1, class ForwardIt2, class BinaryPredicate>
ForwardIt1
findFirstOf(ForwardIt1 first,
            ForwardIt1 second,
            ForwardIt2 first2,
            ForwardIt2 second2,
            BinaryPredicate p);

template<class ForwardIt1, class ForwardIt2, class BinaryPredicate>
ForwardIt1
findFirstOf2(ForwardIt1 first,
             ForwardIt1 second,
             ForwardIt2 first2,
             ForwardIt2 second2,
             BinaryPredicate p);

template<class InputIt, class OutputIt>
OutputIt
copy(InputIt first, InputIt last, OutputIt out);

template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt
copyIf(InputIt first, InputIt last, OutputIt out, UnaryPredicate p);

template<class InputIt, class OutputIt>
OutputIt
move(InputIt first, InputIt last, OutputIt out);

template<class InputIt, class OutputIt, class UnaryPredicate>
OutputIt
moveif(InputIt first, InputIt last, OutputIt out, UnaryPredicate p);

template<class ForwardIt, class T>
ForwardIt
remove(ForwardIt first, ForwardIt last, const T& value);

template<class RanIt, class T>
RanIt
remove2(RanIt first, RanIt last, const T& value);

template<class BidirIt>
void
reverse(BidirIt first, BidirIt last);

template<class BidirIt, class OutputIt>
OutputIt
reverseCopy(BidirIt first, BidirIt last, OutputIt out);

template<class ForwardIt>
ForwardIt
rotate(ForwardIt first, ForwardIt mid, ForwardIt last);

template<class T>
void
swap(T& lhs, T& rhs);

template<class ForwardIt>
ForwardIt
unique(ForwardIt first, ForwardIt last);

template<class ForwardIt, class OutputIt>
ForwardIt
uniqueCopy(ForwardIt first, ForwardIt last, OutputIt out);

template<class RanIt>
void
shuffle(RanIt first, RanIt second);

template<class InputIt, class UnaryPredicate>
bool
isPartitioned(InputIt first, InputIt last, UnaryPredicate p);

template<class ForwardIt, class UnaryPredicate>
ForwardIt
partition(ForwardIt first, ForwardIt last, UnaryPredicate p);

template<class ForwardIt, class T>
ForwardIt
lowerBound(ForwardIt first, ForwardIt last, const T& val);

template<class ForwardIt, class T>
ForwardIt
upperBound(ForwardIt first, ForwardIt last, const T& val);
} // namespace ktl

#include "algorithms.tpp"
