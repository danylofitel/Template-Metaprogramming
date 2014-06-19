#include <iostream>
#include "MetaNumberPrint.h"
#include "MetaTowersOfHanoi.h"
#include "MetaFactorial.h"
#include "MetaGCD.h"
#include "MetaPower.h"
#include "MetaPrimes.h"
#include "MetaFibonnacci.h"
#include "MetaTaylorSeries.h"
#include "MetaContainers.h"

using namespace std;

int main()
{
	cout.precision(20);

	cout << "Natural Number Printing" << endl;
	metaNumberPrint<10>();
	cout << endl;

	cout << "Towers of Hanoi" << endl;
	metaTowersOfHanoi<3, 1, 3, 2>();
	cout << endl;

	cout << "Factorial" << endl;
	cout << metaFactorial<10>() << endl;
	cout << endl;

	cout << "GCD" << endl;
	cout << metaGCD<2, 10>() << endl;
	cout << endl;

	cout << "Power of Integer" << endl;
	cout << metaPowerInt<2, 10>() << endl;
	cout << endl;

	cout << "Power of Double" << endl;
	cout << metaPowerDouble<2>(3.14159) << endl;
	cout << endl;

	cout << "Prime check" << endl;
	cout << metaPrimeCheck<4>() << endl;
	cout << metaPrimeCheck<7>() << endl;
	cout << endl;

	cout << "Prime print" << endl;
	metaPrimePrint<20>();
	cout << endl;

	cout << "Fibonacci" << endl;
	cout << metaFibonacci<1000>() << endl;
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

	cout << "Bitset" << endl;
	MetaBitSet<189> bitset;
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