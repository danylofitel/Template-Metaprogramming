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
bool metaPrimeCheck()
{
	return MetaPrimeCheckHelp<N, 2>::Type::Value;
};

template<>
bool metaPrimeCheck<0>()
{
	return false;
};

template<>
bool metaPrimeCheck<1>()
{
	return false;
};

// Linear Time

template<size_t P, size_t I>
struct MetaPrimeCheckLinearHelp
{
	const bool isPrime;
	MetaPrimeCheckLinearHelp() : isPrime((P % I) && MetaPrimeCheckLinearHelp<P, I - 1>().isPrime)
	{
	}
};

template<size_t P>
struct MetaPrimeCheckLinearHelp<P, 1>
{
	const bool isPrime;
	MetaPrimeCheckLinearHelp() : isPrime(true)
	{
	}
};

template<size_t P>
bool metaPrimeCheckLinear()
{
	return MetaPrimeCheckLinearHelp<P, P - 1>().isPrime;
}

template<>
bool metaPrimeCheckLinear<0>()
{
	return false;
}

template<>
bool metaPrimeCheckLinear<1>()
{
	return false;
}

// Prime Printer

template<size_t N>
struct MetaPrimePrintHelp
{
	MetaPrimePrintHelp()
	{
		MetaPrimePrintHelp<N - 1>();
		if (metaPrimeCheck<N>())
		{
			std::cout << N << " is a prime" << std::endl;
		}
	}
};

template<>
struct MetaPrimePrintHelp<0>
{
	MetaPrimePrintHelp()
	{
	}
};

template<size_t N>
void metaPrimePrint()
{
	MetaPrimePrintHelp<N>();
}

#endif // _META_PRIMES_H_