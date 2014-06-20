#ifndef _META_NUMBER_THEORY_
#define _META_NUMBER_THEORY_

#include "MetaOperators.h"
#include "MetaLoops.h"

template<int u, int v>
struct Divisible
{
	enum { value = v % u == 0 ? 1 : 0 };
};

template<int u>
struct Divisible<u, 0>
{
	enum { value = -1 };
};

template<int u, int v>
struct DivisibleDigit
{
	enum { value = v % u == 0 ? u : 0 };
};

template<int u>
struct DivisibleDigit<u, 0>
{
	enum { value = -1 };
};

template<int u>
struct IsEven
{
	enum { value = Divisible<u, 2>::value };
};

template<int u>
struct IsOdd
{
	enum { value = Divisible<u, 2>::value == 0 ? 1 : 0 };
};

template<int u, int v>
struct GCD
{
	enum { value = GCD<v, u % v>::value };
};

template<int u>
struct GCD<u, 0>
{
	enum { value = u };
};

template<>
struct GCD<0, 0>
{
	enum { value = -1 };
};

template<int u, int v>
struct LCM
{
	enum { value = u * v / GCD<u, v>::value };
};

template<int u, int v>
struct CoPrime
{
	enum { value = GCD<u, v>::value == 1 ? 1 : 0 };
};

template<int a, int b>
struct Power
{
	enum { value = a * Power<a, b - 1>::value };
};

template<int a>
struct Power<a, 0>
{
	enum { value = 1 };
};

template<int n>
struct NoOfDivisor
{
	enum { value = MetaForLoop<1, n, 1, Add, Add, Divisible>::value };
};

template<int n>
class IsPrime
{
public:
	enum { value = NoOfDivisor<n>::value == 2 ? 1 : 0 };
};

template<int n>
struct SumOfDivisor
{
	enum { value = MetaForLoop<1, n, 1, Add, Add, DivisibleDigit>::value };
};

template<int n>
struct IsPerfect
{
	enum { value = SumOfDivisor<n>::value - n == n ? 1 : 0 };
};

template<int n>
struct Totient
{
	enum { value = MetaForLoop<1, n, 1, Add, Add, CoPrime>::value };
};

template<int n, int v = 0>
struct TotientVal
{
	enum { value = Totient<n>::value };
};

template<int n>
struct TotientSummatory
{
	enum { value = MetaForLoop<1, n, 1, Add, Add, TotientVal>::value };
};

template<int n, int x>
struct Divisor
{
	template<int Start, int End>
	struct DivisorPow
	{
		enum { value = Divisible<Start, End>::value == 1 ? Power<Start, x>::value : 0 };
	};

	enum { value = MetaForLoop<1, n, 1, Add, Add, DivisorPow>::value };
};

#endif // _META_NUMBER_THEORY_