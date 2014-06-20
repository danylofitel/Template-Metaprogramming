#ifndef _META_PRIMES_H_
#define _META_PRIMES_H_

#include <iostream>
#include "MetaConditions.h"

// Square Root Time

template<size_t N, size_t C>
struct MetaPrimeCheckHelp
{
	typedef
		typename If<(C * C > N), TrueType,
		typename If<(N % C == 0), FalseType, MetaPrimeCheckHelp<N, C + 1>>::Type>::Type Type;
	enum { Value = Type::Value };
};

template<size_t N>
struct MetaPrimeCheck
{
	enum { value = MetaPrimeCheckHelp<N, 2>::Value };
};

template<>
struct MetaPrimeCheck<0>
{
	enum { value = 0 };
};

template<>
struct MetaPrimeCheck<1>
{
	enum { value = 0 };
};

// Linear Time

template<size_t P, size_t I>
struct MetaPrimeCheckLinearHelp
{
	enum { value = (P % I) && MetaPrimeCheckLinearHelp<P, I - 1>::value };
};

template<size_t P>
struct MetaPrimeCheckLinearHelp<P, 1>
{
	enum { value = 1 };
};

template<size_t P>
struct MetaPrimeCheckLinear
{
	enum { value = MetaPrimeCheckLinearHelp<P, P - 1>::value };
};

template<>
struct MetaPrimeCheckLinear<0>
{
	enum { value = false };
};

template<>
struct MetaPrimeCheckLinear<1>
{
	enum { value = false };
};

// Prime Printer

template<size_t N>
void metaPrimePrint()
{
	metaPrimePrint<N - 1>();
	if (MetaPrimeCheck<N>::value)
	{
		std::cout << N << " is a prime" << std::endl;
	}
}

template<>
void metaPrimePrint<0>()
{
}

#endif // _META_PRIMES_H_