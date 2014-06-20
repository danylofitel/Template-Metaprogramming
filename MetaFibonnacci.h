#ifndef _META_FIBONACCI_H_
#define _META_FIBONACCI_H_

// Logarithmic Time

template<size_t Pow, size_t A11, size_t A12, size_t A21, size_t A22>
struct SymmetricalMatrix2X2Power
{
	static_assert(A12 == A21, "Matrix has to be symmetrical");

	static const size_t s11 = A11 * A11 + A12 * A21;
	static const size_t s12 = A11 * A21 + A12 * A22;
	static const size_t s21 = A21 * A11 + A22 * A21;
	static const size_t s22 = A21 * A21 + A22 * A22;

	typedef SymmetricalMatrix2X2Power<Pow / 2, s11, s12, s21, s22> SQ;

	static const size_t _11 = Pow % 2 ? A11 * SQ::_11 + A12 * SQ::_21 : SQ::_11;
	static const size_t _12 = Pow % 2 ? A11 * SQ::_21 + A12 * SQ::_22 : SQ::_12;
	static const size_t _21 = Pow % 2 ? A21 * SQ::_11 + A22 * SQ::_21 : SQ::_21;
	static const size_t _22 = Pow % 2 ? A21 * SQ::_21 + A22 * SQ::_22 : SQ::_22;

};

template<size_t A11, size_t A12, size_t A21, size_t A22>
struct SymmetricalMatrix2X2Power < 0, A11, A12, A21, A22 >
{
	static_assert(A12 == A21, "Matrix has to be symmetrical");

	static const size_t
		_11 = 1, _12 = 0,
		_21 = 0, _22 = 1;
};

template<size_t N>
struct MetaFibonacci
{
	enum { value = SymmetricalMatrix2X2Power<N - 1, 1, 1, 1, 0>::_11 };
};

template<>
struct MetaFibonacci<0>
{
	enum { value = 0 };
};

// Linear Time

template<size_t N>
struct MetaFibonacciLinearHelp
{
	static const size_t prev = MetaFibonacciLinearHelp<N - 1>::curr;
	static const size_t curr = MetaFibonacciLinearHelp<N - 1>::prev + MetaFibonacciLinearHelp<N - 1>::curr;
};

template<>
struct MetaFibonacciLinearHelp<0>
{
	static const size_t prev = 0;
	static const size_t curr = 0;
};

template<>
struct MetaFibonacciLinearHelp<1>
{
	static const size_t prev = 0;
	static const size_t curr = 1;
};

template<size_t N>
struct MetaFibonacciLinear
{
	enum { value = MetaFibonacciLinearHelp<N>::curr };
};

// Exponential Time (actually, linear time, still more lookups than in the previous one)

template<size_t N>
struct MetaFibonacciExponential
{
	enum { value = MetaFibonacciExponential<N - 2>::value + MetaFibonacciExponential<N - 1>::value };
};

template<>
struct MetaFibonacciExponential<0>
{
	enum { value = 0 };
};

template<>
struct MetaFibonacciExponential<1>
{
	enum { value = 1 };
};

#endif // _META_FIBONACCI_H_