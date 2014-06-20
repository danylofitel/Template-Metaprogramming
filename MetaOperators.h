#ifndef _META_OPERATORS_H_
#define _META_OPERATORS_H_

template<int U, int V = 0>
struct MetaAdd
{
	enum { value = U + V };
};

template<int U, int V = 0>
struct MetaSubtract
{
	enum { value = U - V };
};

template<int U, int V = 1>
struct MetaMultiply
{
	enum { value = U * V };
};

template<int U, int V = 1>
struct MetaDivide
{
	enum { value = U / V };
};

template<int U, int V>
struct MetaMod
{
	enum { value = U % V };
};

#endif // _META_OPERATORS_H_