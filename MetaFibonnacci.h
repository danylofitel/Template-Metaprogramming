#ifndef _META_FIBONACCI_H_
#define _META_FIBONACCI_H_

template <size_t N>
size_t metaFibonacci()
{
	return SymmetricalMatrix2X2Power<N - 1, 1, 1, 1, 0>()._11;
}

template <size_t Pow, size_t A11, size_t A12, size_t A21, size_t A22>
struct SymmetricalMatrix2X2Power
{
	size_t
		_11, _12,
		_21, _22;
	SymmetricalMatrix2X2Power()
	{
		static_assert(A12 == A21, "Matrix has to be symmetrical");
		const size_t s11 = A11 * A11 + A12 * A21;
		const size_t s12 = A11 * A21 + A12 * A22;
		const size_t s21 = A21 * A11 + A22 * A21;
		const size_t s22 = A21 * A21 + A22 * A22;

		SymmetricalMatrix2X2Power<Pow / 2, s11, s12, s21, s22> sq;

		if (Pow % 2)
		{
			_11 = A11 * sq._11 + A12 * sq._21;
			_12 = A11 * sq._21 + A12 * sq._22;
			_21 = A21 * sq._11 + A22 * sq._21;
			_22 = A21 * sq._21 + A22 * sq._22;
		}
		else
		{
			_11 = sq._11;
			_12 = sq._12;
			_21 = sq._21;
			_22 = sq._22;
		}
	}
};

template <size_t A11, size_t A12, size_t A21, size_t A22>
struct SymmetricalMatrix2X2Power <0, A11, A12, A21, A22>
{
	const size_t
		_11 = 1, _12 = 0,
		_21 = 0, _22 = 1;
	SymmetricalMatrix2X2Power()
	{
		static_assert(A12 == A21, "Matrix has to be symmetrical");
	}
};

#endif // _META_FIBONACCI_H_