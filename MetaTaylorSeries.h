#ifndef _META_TAYLOR_SERIES_H_
#define _META_TAYLOR_SERIES_H_

#include <exception>

const size_t SEQUENCE_SIZE = 100;

// Pi

template<size_t Depth>
double metaPiHelp(const bool positive)
{
	return (positive ? 1.0 : -1.0) / ((2 * Depth) * (2 * Depth + 1) * (2 * Depth + 2)) + metaPiHelp<Depth + 1>(!positive);
}

template<>
double metaPiHelp<SEQUENCE_SIZE>(const bool positive)
{
	return (positive ? 1.0 : -1.0) / ((2 * SEQUENCE_SIZE) * (2 * SEQUENCE_SIZE + 1) * (2 * SEQUENCE_SIZE + 2));
}

double metaPi()
{
	return 3.0 + 4.0 * metaPiHelp<1>(true);
}

// E

template<size_t Depth>
double metaEHelp(const double acc)
{
	return 1 / acc + metaEHelp<Depth + 1>(acc * Depth);
}

template<>
double metaEHelp<SEQUENCE_SIZE>(const double acc)
{
	return 1 / acc;
}

double metaE()
{
	return metaEHelp<1>(1);
}

// Square Root

template<size_t Depth>
double metaSquareRootHelp(const double x)
{
	double prev = metaSquareRootHelp<Depth - 1>(x);
	return 0.5 * (prev + x / prev);
}

template<>
double metaSquareRootHelp<0>(const double x)
{
	return x;
}

double metaSquareRoot(const double x)
{
	return metaSquareRootHelp<SEQUENCE_SIZE>(x);
}

// Exponent

template<size_t Depth>
double metaExponentHelp(const double x, const double xn, const double fact)
{
	return xn / fact + metaExponentHelp<Depth + 1>(x, xn * x, fact * Depth);
}

template<>
double metaExponentHelp<SEQUENCE_SIZE>(const double x, const double xn, const double fact)
{
	return xn / fact;
}

double metaExponent(const double x)
{
	return metaExponentHelp<1>(x, 1, 1);
}

// Natural Logarithm

template<size_t Depth>
double metaNaturalLogarithmHelp(const double x, const double xn)
{
	return xn / Depth + metaNaturalLogarithmHelp<Depth + 1>(x, xn * x);
}

template<>
double metaNaturalLogarithmHelp<SEQUENCE_SIZE>(const double x, const double xn)
{
	return xn / SEQUENCE_SIZE;
}

double metaNaturalLogarithm(const double x)
{
	if (x <= -1 || x >= 1)
	{
		throw std::invalid_argument("x has to be between -1 and 1 exclusively");
	}
	return -metaNaturalLogarithmHelp<1>(1 - x, x);
}

// Geometric Series 1 / (1-x)

template<size_t Depth>
double metaGeometricSeriesHelp(const double x, const double xn)
{
	return xn + metaGeometricSeriesHelp<Depth + 1>(x, xn * x);
}

template<>
double metaGeometricSeriesHelp<SEQUENCE_SIZE>(const double x, const double xn)
{
	return xn;
}

double metaGeometricSeries(const double x)
{
	if (x <= -1 || x >= 1)
	{
		throw std::invalid_argument("x has to be between -1 and 1 exclusively");
	}
	return metaGeometricSeriesHelp<0>(x, 1);
}

// Binomial Series (1 + x)^A

template<size_t A, size_t Depth>
struct MetaBinomialSeriesHelp
{
	const double val;
	MetaBinomialSeriesHelp(const double x, const double xn, const double coeff) : val(xn * coeff + MetaBinomialSeriesHelp<A, Depth + 1>(x, xn * x, coeff * (A - Depth) / (Depth + 1)).val)
	{
	}
};

template<size_t A>
struct MetaBinomialSeriesHelp<A, SEQUENCE_SIZE>
{
	const double val;
	MetaBinomialSeriesHelp(const double x, const double xn, const double coeff) : val(xn * coeff)
	{
	}
};

template<size_t A>
double metaBinomialSeries(const double x)
{
	if (x <= -1 || x >= 1)
	{
		throw std::invalid_argument("x has to be between -1 and 1 exclusively");
	}
	return MetaBinomialSeriesHelp<A, 0>(x, 1, 1).val;
}

// Sin

template<size_t Depth>
struct MetaSinHelp
{
	const double val;
	MetaSinHelp(const double x2, const double xn, const double coeff, const bool positive) : val((positive ? 1.0 : -1.0) * xn * coeff + MetaSinHelp<Depth + 1>(x2, xn * x2, coeff / ((2 * Depth) * (2 * Depth + 1)), !positive).val)
	{
	}
};

template<>
struct MetaSinHelp<SEQUENCE_SIZE>
{
	const double val;
	MetaSinHelp(const double x2, const double xn, const double coeff, const bool positive) : val((positive ? 1.0 : -1.0) * xn * coeff)
	{
	}
};

double MetaSin(const double x)
{
	return MetaSinHelp<1>(x * x, x, 1, true).val;
}

// Cos

template<size_t Depth>
struct MetaCosHelp
{
	const double val;
	MetaCosHelp(const double x2, const double xn, const double coeff, const bool positive) : val((positive ? 1.0 : -1.0) * xn * coeff + MetaCosHelp<Depth + 1>(x2, xn * x2, coeff / ((2 * Depth - 1) * (2 * Depth)), !positive).val)
	{
	}
};

template<>
struct MetaCosHelp<SEQUENCE_SIZE>
{
	const double val;
	MetaCosHelp(const double x2, const double xn, const double coeff, const bool positive) : val((positive ? 1.0 : -1.0) * xn * coeff)
	{
	}
};

double MetaCos(const double x)
{
	return MetaCosHelp<1>(x * x, 1, 1, true).val;
}

// Sinh

template<size_t Depth>
struct MetaSinhHelp
{
	const double val;
	MetaSinhHelp(const double x2, const double xn, const double coeff) : val(xn * coeff + MetaSinhHelp<Depth + 1>(x2, xn * x2, coeff / ((2 * Depth) * (2 * Depth + 1))).val)
	{
	}
};

template<>
struct MetaSinhHelp<SEQUENCE_SIZE>
{
	const double val;
	MetaSinhHelp(const double x2, const double xn, const double coeff) : val(xn * coeff)
	{
	}
};

double MetaSinh(const double x)
{
	return MetaSinhHelp<1>(x * x, x, 1).val;
}

// Cosh

template<size_t Depth>
struct MetaCoshHelp
{
	const double val;
	MetaCoshHelp(const double x2, const double xn, const double coeff) : val(xn * coeff + MetaCoshHelp<Depth + 1>(x2, xn * x2, coeff / ((2 * Depth - 1) * (2 * Depth))).val)
	{
	}
};

template<>
struct MetaCoshHelp<SEQUENCE_SIZE>
{
	const double val;
	MetaCoshHelp(const double x2, const double xn, const double coeff) : val(xn * coeff)
	{
	}
};

double MetaCosh(const double x)
{
	return MetaCoshHelp<1>(x * x, 1, 1).val;
}

#endif // _META_TAYLOR_SERIES_H_