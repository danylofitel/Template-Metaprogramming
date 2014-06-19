#include <iostream>
#include "MetaNumberPrint.h"
#include "MetaTowersOfHanoi.h"
#include "MetaFactorial.h"
#include "MetaGCD.h"
#include "MetaPower.h"
#include "MetaFibonnacci.h"
#include "MetaTaylor.h"

using namespace std;

int main()
{
	cout.precision(20);

	metaNumberPrint<10>();
	cout << endl;

	metaTowersOfHanoi<3, 1, 3, 2>();
	cout << endl;

	cout << metaFactorial<10>() << endl;
	cout << endl;

	cout << metaGCD<2, 10>() << endl;
	cout << endl;

	cout << metaPowerInt<2, 10>() << endl;
	cout << endl;

	cout << metaPowerDouble<2>(3.14159) << endl;
	cout << endl;

	cout << metaFibonacci<1000>() << endl;
	cout << endl;

	cout << metaSquareRoot(2) << endl;
	cout << endl;

	cout << metaE() << endl;
	cout << endl;

	cout << metaExponent(2) << endl;
	cout << endl;

	cout << metaNaturalLogarithm(0.5) << endl;
	cout << endl;

	cout << metaGeometricSeries(0.5) << endl;
	cout << endl;
	
	return 0;
}