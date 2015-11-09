#include <iostream>
#include "MetaNumberPrint.h"
#include "MetaTowersOfHanoi.h"
#include "MetaNumberTheory.h"
#include "MetaFactorial.h"
#include "MetaPower.h"
#include "MetaPrimes.h"
#include "MetaFibonnacci.h"
#include "MetaTaylorSeries.h"
#include "MetaBubbleSort.h"
#include "MetaBitset.h"
#include "MetaTuringMachine.h"

using namespace std;

template<>
char const* Input<-1>::name = "_";

char const* QAccept::name = "qaccept";
char const* QReject::name = "qreject";

int main()
{
	cout.precision(36);

	cout << "Natural Number Printing" << endl;
	metaNumberPrint<10>();
	cout << endl;

	cout << "Towers of Hanoi" << endl;
	metaTowersOfHanoi<3, 1, 3, 2>();
	cout << endl;

	cout << "Number Theory" << endl;
	cout << MetaDivisible<5, 2>::value << endl;
	cout << MetaDivisibleDigit<5, 2>::value << endl;
	cout << MetaIsEven<111>::value << endl;
	cout << MetaIsOdd<112>::value << endl;
	cout << MetaGCD<15, 10>().value << endl;
	cout << MetaLCM<15, 10>().value << endl;
	cout << MetaCoPrime<190, 189>::value << endl;
	cout << MetaIntPower<2, 10>::value << endl;
	cout << MetaNoOfDivisor<25>::value << endl;
	cout << MetaIsPrime<191>::value << endl;
	cout << MetaSumOfDivisor<66>::value << endl;
	cout << MetaIsPerfect<28>::value << endl;
	cout << MetaTotient<99>::value << endl;
	cout << MetaTotientVal<100>::value << endl;
	cout << MetaTotientSummatory<10>::value << endl;
	cout << MetaDivisor<20, 5>::value << endl;
	cout << endl;

	cout << "Factorial" << endl;
	cout << MetaFactorial<10>::value << endl;
	cout << endl;

	cout << "Double Factorial" << endl;
	cout << MetaDoubleFactorial<9>::value << endl;
	cout << MetaDoubleFactorial<10>::value << endl;
	cout << endl;

	cout << "Arrangements" << endl;
	cout << MetaArrangements<5, 5>::value << endl;
	cout << endl;

	cout << "Combinations" << endl;
	cout << MetaCombinations<10, 10>::value << endl;
	cout << endl;

	cout << "Power of Integer" << endl;
	cout << MetaPowerInt<-2, 11>::value << endl;
	cout << MetaPowerIntLinear<2, 10>::value << endl;
	cout << endl;

	cout << "Power" << endl;
	cout << metaPower<double, 2>(metaPi()) << endl;
	cout << metaPowerLinear<double, 3>(metaE()) << endl;
	cout << endl;

	cout << "Prime Check" << endl;
	cout << MetaPrimeCheck<271>::value << endl;
	cout << MetaPrimeCheckLinear<24>::value << endl;
	cout << endl;

	cout << "Prime Print" << endl;
	metaPrimePrint<20>();
	cout << endl;

	cout << "Fibonacci" << endl;
	cout << MetaFibonacci<40>::value << endl;
	cout << MetaFibonacciLinear<20>::value << endl;
	cout << MetaFibonacciExponential<10>::value << endl;
	cout << endl;

	cout << "Pi" << endl;
	cout << metaPi() << endl;
	cout << endl;

	cout << "E" << endl;
	cout << metaE() << endl;
	cout << endl;

	cout << "Square Root" << endl;
	cout << metaSquareRoot(2) << endl;
	cout << endl;

	cout << "Exponent" << endl;
	cout << metaExponent(2) << endl;
	cout << endl;

	cout << "Natural Logarithm" << endl;
	cout << metaNaturalLogarithm(0.5) << endl;
	cout << endl;

	cout << "Geometric series" << endl;
	cout << metaGeometricSeries(0.5) << endl;
	cout << endl;

	cout << "Binomial Series" << endl;
	cout << metaBinomialSeries<2>(0.5) << endl;
	cout << endl;

	cout << "Sin" << endl;
	cout << MetaSin(1) << endl;
	cout << endl;

	cout << "Cos" << endl;
	cout << MetaCos(1) << endl;
	cout << endl;

	cout << "Sinh" << endl;
	cout << MetaSinh(1) << endl;
	cout << endl;

	cout << "Cosh" << endl;
	cout << MetaCosh(1) << endl;
	cout << endl;

	cout << "Bubble Sort" << endl;
	const size_t arraySize = 10;
	int intArray[] = { 4, 9, 0, 1, 5, 6, 3, 8, 7, 2 };

	MetaBubbleSort<int, arraySize>::sort(intArray);
	for (auto i = 0; i < arraySize; ++i)
	{
		cout << intArray[i] << endl;
	}
	cout << endl;

	cout << "Bitset" << endl;
	MetaBitset<189> bitset;
	cout << bitset.B0 << endl;
	cout << bitset.B1 << endl;
	cout << bitset.B2 << endl;
	cout << bitset.B3 << endl;
	cout << bitset.B4 << endl;
	cout << bitset.B5 << endl;
	cout << bitset.B6 << endl;
	cout << bitset.B7 << endl;
	cout << bitset.SUM << endl;
	cout << endl;

	cout << "Turing Machine" << endl;

	DEF_INPUT(1, x);
	DEF_INPUT(2, x_mark);
	DEF_INPUT(3, split);

	DEF_STATE(0, start);
	DEF_STATE(1, find_blank);
	DEF_STATE(2, go_back);

	/* syntax:  State, Input, NewState, Output, Move */
	typedef TypeList<
		Rule<start, x, find_blank, x_mark, Right>,
		Rule<find_blank, x, find_blank, x, Right>,
		Rule<find_blank, split, find_blank, split, Right>,
		Rule<find_blank, InputBlank, go_back, x, Left>,
		Rule<go_back, x, go_back, x, Left>,
		Rule<go_back, split, go_back, split, Left>,
		Rule<go_back, x_mark, start, x, Right>,
		Rule<start, split, QAccept, split, Left >> rules;

	/* syntax: initial input, rules, start state */
	typedef TuringMachine<TypeList<x, x, x, x, split>, rules, start> double_it;
	static_assert(IsSame<double_it::end_input,
		TypeList<x, x, x, x, split, x, x, x, x >> ::value,
		"Hmm... This is borky!");

	cout << endl;
	
	return 0;
}