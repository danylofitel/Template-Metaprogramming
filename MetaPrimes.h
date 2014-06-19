#ifndef _META_PRIMES_H_
#define _META_PRIMES_H_

#include <iostream>

template <size_t P, size_t I>
struct MetaPrimeCheckHelp
{
	const bool isPrime;
	MetaPrimeCheckHelp() : isPrime((P % I) && MetaPrimeCheckHelp<P, I - 1>().isPrime)
	{
	}
};

template <size_t P>
struct MetaPrimeCheckHelp<P, 1>
{
	const bool isPrime;
	MetaPrimeCheckHelp() : isPrime(true)
	{
	}
};

template <size_t P>
bool metaPrimeCheck()
{
	return MetaPrimeCheckHelp<P, P - 1>().isPrime;
}

template <>
bool metaPrimeCheck<0>()
{
	return false;
}

template <>
bool metaPrimeCheck<1>()
{
	return false;
}

template <size_t N>
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

template <>
struct MetaPrimePrintHelp<0>
{
	MetaPrimePrintHelp()
	{
	}
};

template <size_t N>
void metaPrimePrint()
{
	MetaPrimePrintHelp<N>();
}

#endif // _META_PRIMES_H_