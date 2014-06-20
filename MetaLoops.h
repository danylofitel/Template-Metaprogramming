#ifndef _META_LOOPS_H_
#define _META_LOOPS_H_

template<int Start, int End, int Exp = 1,
	template<int U, int V> class ExpOperator,
	template<int U, int V> class Operator,
	template<int U, int V> class BiFun>
struct MetaForLoop
{
	enum
	{
		value = Operator<BiFun<Start, End>::value,
		MetaForLoop<ExpOperator<Start, Exp>::value, End, Exp, ExpOperator, Operator, BiFun>::value>::value
	};
};

template<int End, int Exp,
	template<int U, int V> class ExpOperator,
	template<int U, int V> class Operator,
	template<int U, int V> class BiFun>
struct MetaForLoop<End, End, Exp, ExpOperator, Operator, BiFun>
{
	enum { value = BiFun<End, End>::value };
};

#endif // _META_LOOPS_H_