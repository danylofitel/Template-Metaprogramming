#ifndef _META_POWER_H_
#define _META_POWER_H_

template <size_t Arg, size_t Pow>
size_t metaPowerInt()
{
	return MetaPowerIntHelp<Pow, Arg>().exp;
}

template <size_t Pow, size_t Mul>
struct MetaPowerIntHelp
{
	const size_t exp;
	MetaPowerIntHelp() : exp((Pow & 1 ? Mul : 1) * (MetaPowerIntHelp<Pow / 2, Mul * Mul>().exp))
	{
	}
};

template <size_t Mul>
struct MetaPowerIntHelp<0, Mul>
{
	const size_t exp = 1;
};

template <size_t Pow>
double metaPowerDouble(const double x)
{
	return MetaPowerDoubleHelp<Pow>(x).exp;
}

template <size_t Pow>
struct MetaPowerDoubleHelp
{
	const double exp;
	MetaPowerDoubleHelp(const double mul) : exp((Pow & 1 ? mul : 1.0) * (MetaPowerDoubleHelp<Pow / 2>(mul * mul).exp))
	{
	}
};

template <>
struct MetaPowerDoubleHelp<0>
{
	const double exp;
	MetaPowerDoubleHelp(const double mul) : exp(1.0)
	{
	}
};

#endif // _META_POWER_H_