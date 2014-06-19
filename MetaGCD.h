#ifndef _META_GCD_H_
#define _META_GCD_H_

template <size_t X, size_t Y>
size_t metaGCD()
{
	return MetaGCD<X, Y>().gcd;
}

template <size_t X, size_t Y>
struct MetaGCD
{
	const size_t gcd = X > Y ? MetaGCD<Y, X % Y>().gcd : MetaGCD<X, Y % X>().gcd;
};

template <size_t X>
struct MetaGCD<X, 0>
{
	const size_t gcd = X;
};

template <size_t X>
struct MetaGCD<0, X>
{
	const size_t gcd = X;
};

#endif // _META_GCD_H_