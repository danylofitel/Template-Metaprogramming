#ifndef _META_OPERATORS_H_
#define _META_OPERATORS_H_

template<int U, int V = 0>
struct Add
{
	enum { value = U + V };
};

template<int U, int V = 0>
struct Subtract
{
	enum { value = U - V };
};

template<int U, int V = 1>
struct Multiply
{
	enum { value = U * V };
};

template<int U, int V = 1>
struct Divide
{
	enum { value = U / V };
};

template<int U, int V>
struct Mod
{
	enum { value = U % V };
};

#endif // _META_OPERATORS_H_