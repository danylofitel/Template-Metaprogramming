#ifndef _META_TAYLOR_H_
#define _META_TAYLOR_H_

#include <exception>

const size_t SEQUENCE_SIZE = 100;

// Square Root

template <size_t Depth>
double metaSquareRootHelp(const double x)
{
	double prev = metaSquareRootHelp<Depth - 1>(x);
	return 0.5 * (prev + x / prev);
}

template <>
double metaSquareRootHelp<0>(const double x)
{
	return x;
}

double metaSquareRoot(const double x)
{
	return metaSquareRootHelp<SEQUENCE_SIZE>(x);
}

// E

template <size_t Depth>
double metaEHelp(const double acc)
{
	return 1 / acc + metaEHelp<Depth + 1>(acc * Depth);
}

template <>
double metaEHelp<SEQUENCE_SIZE>(const double acc)
{
	return 1 / acc;
}

double metaE()
{
	return metaEHelp<1>(1);
}

// Exponent

template <size_t Depth>
double metaExponentHelp(const double x, const double xn, const double fact)
{
	return xn / fact + metaExponentHelp<Depth + 1>(x, xn * x, fact * Depth);
}

template <>
double metaExponentHelp<SEQUENCE_SIZE>(const double x, const double xn, const double fact)
{
	return xn / fact;
}

double metaExponent(const double x)
{
	return metaExponentHelp<1>(x, 1, 1);
}

// Natural Logarithm

template <size_t Depth>
double metaNaturalLogarithmHelp(const double x, const double xn)
{
	return xn / Depth + metaNaturalLogarithmHelp<Depth + 1>(x, xn * x);
}

template <>
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

template <size_t Depth>
double metaGeometricSeriesHelp(const double x, const double xn)
{
	return xn + metaGeometricSeriesHelp<Depth + 1>(x, xn * x);
}

template <>
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

// Binomial Series

// Trigonoetric Functions

#endif