#ifndef _META_CONDITIONS_H_
#define _META_CONDITIONS_H_

struct FalseType
{
	typedef FalseType Type;
	enum { Value = 0 };
};

struct TrueType
{
	typedef TrueType Type;
	enum { Value = 1 };
};

template<bool Condition, class Then, class Else>
struct If;

template<class Then, class Else>
struct If<true, Then, Else>
{
	typedef Then Type;
};

template<class Then, class Else>
struct If<false, Then, Else>
{
	typedef Else Type;
};

#endif // _META_CONDITIONS_H_