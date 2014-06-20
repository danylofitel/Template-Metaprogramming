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

using namespace std;

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
	cout << Divisible<5, 2>::value << endl;
	cout << DivisibleDigit<5, 2>::value << endl;
	cout << IsEven<111>::value << endl;
	cout << IsOdd<112>::value << endl;
	cout << GCD<15, 10>().value << endl;
	cout << LCM<15, 10>().value << endl;
	cout << CoPrime<190, 189>::value << endl;
	cout << Power<2, 10>::value << endl;
	cout << NoOfDivisor<25>::value << endl;
	cout << IsPrime<191>::value << endl;
	cout << SumOfDivisor<66>::value << endl;
	cout << IsPerfect<28>::value << endl;
	cout << Totient<99>::value << endl;
	cout << TotientVal<100>::value << endl;
	cout << TotientSummatory<10>::value << endl;
	cout << Divisor<20, 5>::value << endl;
	cout << endl;

	cout << "Factorial" << endl;
	cout << MetaFactorial<10>::value << endl;
	cout << endl;

	cout << "Arrangements" << endl;
	cout << MetaArrangements<5, 5>::value << endl;
	cout << endl;

	cout << "Combinations" << endl;
	cout << MetaCombinations<10, 10>::value << endl;
	cout << endl;

	cout << "Power of Integer" << endl;
	cout << metaPowerInt<-2, 20>() << endl;
	cout << metaPowerIntLinear<-2, 11>() << endl;
	cout << endl;

	cout << "Power" << endl;
	cout << metaPower<double, 2>(metaPi()) << endl;
	cout << metaPowerLinear<double, 3>(metaE()) << endl;
	cout << endl;

	cout << "Prime Check" << endl;
	cout << metaPrimeCheck<271>() << endl;
	cout << metaPrimeCheckLinear<12>() << endl;
	cout << endl;

	cout << "Prime Print" << endl;
	metaPrimePrint<20>();
	cout << endl;

	cout << "Fibonacci" << endl;
	cout << metaFibonacci<1000>() << endl;
	cout << metaFibonacciLinear<100>() << endl;
	cout << metaFibonacciExponential<10>() << endl;
	cout << endl;

	cout << "Square Root" << endl;
	cout << metaSquareRoot(2) << endl;
	cout << endl;

	cout << "Pi" << endl;
	cout << metaPi() << endl;
	cout << endl;

	cout << "E" << endl;
	cout << metaE() << endl;
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
	
	return 0;
}