#ifndef _META_NUMBER_THEORY_
#define _META_NUMBER_THEORY_

#include "MetaOperators.h"
#include "MetaLoops.h"

template<int U, int V>
struct MetaDivisible
{
	enum { value = V % U == 0 ? 1 : 0 };
};

template<int U>
struct MetaDivisible<U, 0>
{
	enum { value = -1 };
};

template<int U, int V>
struct MetaDivisibleDigit
{
	enum { value = V % U == 0 ? U : 0 };
};

template<int U>
struct MetaDivisibleDigit<U, 0>
{
	enum { value = -1 };
};

template<int U>
struct MetaIsEven
{
	enum { value = MetaDivisible<U, 2>::value };
};

template<int U>
struct MetaIsOdd
{
	enum { value = MetaDivisible<U, 2>::value == 0 ? 1 : 0 };
};

template<int U, int V>
struct MetaGCD
{
	enum { value = MetaGCD<V, U % V>::value };
};

template<int U>
struct MetaGCD<U, 0>
{
	enum { value = U };
};

template<>
struct MetaGCD<0, 0>
{
	enum { value = -1 };
};

template<int U, int V>
struct MetaLCM
{
	enum { value = U * V / MetaGCD<U, V>::value };
};

template<int U, int V>
struct MetaCoPrime
{
	enum { value = MetaGCD<U, V>::value == 1 ? 1 : 0 };
};

template<int a, int b>
struct MetaIntPower
{
	enum { value = a * MetaIntPower<a, b - 1>::value };
};

template<int a>
struct MetaIntPower<a, 0>
{
	enum { value = 1 };
};

template<int N>
struct MetaNoOfDivisor
{
	enum { value = MetaForLoop<1, N, 1, MetaAdd, MetaAdd, MetaDivisible>::value };
};

template<int N>
class MetaIsPrime
{
public:
	enum { value = MetaNoOfDivisor<N>::value == 2 ? 1 : 0 };
};

template<int N>
struct MetaSumOfDivisor
{
	enum { value = MetaForLoop<1, N, 1, MetaAdd, MetaAdd, MetaDivisibleDigit>::value };
};

template<int N>
struct MetaIsPerfect
{
	enum { value = MetaSumOfDivisor<N>::value - N == N ? 1 : 0 };
};

template<int N>
struct MetaTotient
{
	enum { value = MetaForLoop<1, N, 1, MetaAdd, MetaAdd, MetaCoPrime>::value };
};

template<int N, int V = 0>
struct MetaTotientVal
{
	enum { value = MetaTotient<N>::value };
};

template<int N>
struct MetaTotientSummatory
{
	enum { value = MetaForLoop<1, N, 1, MetaAdd, MetaAdd, MetaTotientVal>::value };
};

template<int N, int X>
struct MetaDivisor
{
	template<int Start, int End>
	struct DivisorPow
	{
		enum { value = MetaDivisible<Start, End>::value == 1 ? MetaIntPower<Start, X>::value : 0 };
	};

	enum { value = MetaForLoop<1, N, 1, MetaAdd, MetaAdd, DivisorPow>::value };
};

#endif // _META_NUMBER_THEORY_