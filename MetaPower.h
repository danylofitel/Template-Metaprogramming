#ifndef _META_POWER_H_
#define _META_POWER_H_

// Logarithmic Time

template<size_t Pow, int Mul>
struct MetaPowerIntHelp
{
	enum { value = (Pow & 1 ? Mul : 1) * (MetaPowerIntHelp<Pow / 2, Mul * Mul>::value) };
};

template<int Mul>
struct MetaPowerIntHelp<0, Mul>
{
	enum { value = 1 };
};

template<int Arg, size_t Pow>
struct MetaPowerInt
{
	enum { value = MetaPowerIntHelp<Pow, Arg>::value };
};

template<class T, size_t Pow>
struct MetaPowerHelp
{
	const T exp;
	MetaPowerHelp(const T & mul) : exp((Pow & 1 ? mul : 1.0) * (MetaPowerHelp<T, Pow / 2>(mul * mul).exp))
	{
	}
};

template<class T>
struct MetaPowerHelp<T, 0>
{
	const double exp;
	MetaPowerHelp(const T & mul) : exp(static_cast<T>(1))
	{
	}
};

template<class T, size_t Pow>
double metaPower(const T & x)
{
	return MetaPowerHelp<T, Pow>(x).exp;
}

// Linear Time

template<int Arg, size_t Pow>
struct MetaPowerIntLinear
{
	enum { value = Arg * MetaPowerIntLinear<Arg, Pow - 1>::value };
};

template<int Arg>
struct MetaPowerIntLinear<Arg, 0>
{
	enum { value = 1};
};

template<class T, size_t Pow>
struct MetaPowerLinearHelp
{
	const T exp;
	MetaPowerLinearHelp(const T & mul) : exp(mul * MetaPowerLinearHelp<T, Pow - 1>(mul).exp)
	{
	}
};

template<class T>
struct MetaPowerLinearHelp<T, 0>
{
	const T exp;
	MetaPowerLinearHelp(const T & mul) : exp(static_cast<T>(1))
	{
	}
};

template<class T, size_t Pow>
double metaPowerLinear(const T & x)
{
	return MetaPowerLinearHelp<T, Pow>(x).exp;
}

#endif // _META_POWER_H_