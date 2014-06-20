#ifndef _META_FACTORIAL_H_
#define _META_FACTORIAL_H_

template<size_t N>
struct MetaFactorial
{
	enum { value = N * MetaFactorial<N - 1>::value };
};

template<>
struct MetaFactorial<0>
{
	enum { value = 1 };
};

template<size_t N, size_t K>
struct MetaArrangements
{
	static_assert(N >= K, "N can't be smaller than K");
	enum { value = MetaFactorial<N>::value / MetaFactorial<N - K>::value };
};

template<size_t N, size_t K>
struct MetaCombinations
{
	static_assert(N >= K, "N can't be smaller than K");
	enum { value = N * MetaCombinations<N - 1, K - 1>::value / K };
};

template<size_t N>
struct MetaCombinations<N, 0>
{
	enum { value = 1 };
};

#endif // _META_FACTORIAL_H_