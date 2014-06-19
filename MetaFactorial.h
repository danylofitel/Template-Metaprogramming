#ifndef _META_FACTORIAL_H_
#define _META_FACTORIAL_H_

template <size_t N>
size_t metaFactorial()
{
	return N * metaFactorial<N - 1>();
}

template <>
size_t metaFactorial<0>()
{
	return 1;
}

#endif // _META_FACTORIAL_H_