#pragma once 

namespace ktl
{

template< class InputIt, class T>
InputIt find( InputIt first, InputIt second, const T& val);

template< class InputIt, class UnaryPredicate>
InputIt findIf( InputIt first, InputIt second, UnaryPredicate p);

template< class InputIt, class UnaryPredicate>
InputIt findIfNot( InputIt first, InputIt second, UnaryPredicate p);

template< class InputIt, class UnaryPredicate>
bool allOf( InputIt first, InputIt second, UnaryPredicate p);

template< class InputIt, class UnaryPredicate>
bool  anyOf( InputIt first, InputIt second, UnaryPredicate p);

template< class InputIt, class UnaryPredicate>
bool noneOf( InputIt first, InputIt second, UnaryPredicate p);

template< class InputIt, class UnaryPredicate>
UnaryPredicate forEach( InputIt first, InputIt second, UnaryPredicate p);

template< class ForwardIt1, class ForwardIt2, class BinaryPredicate>
ForwardIt1 findFirstOf(ForwardIt1 first, ForwardIt1 second, ForwardIt2 first2, ForwardIt2 second2, BinaryPredicate p);

template< class ForwardIt1, class ForwardIt2, class BinaryPredicate>
ForwardIt1 findFirstOf2(ForwardIt1 first, ForwardIt1 second, ForwardIt2 first2, ForwardIt2 second2, BinaryPredicate p);



}

#include "algorithms.tpp"
