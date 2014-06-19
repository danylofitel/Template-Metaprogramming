#ifndef _META_NUMNER_PRINTER_H_
#define _META_NUMBER_PRINTER_H_

#include <iostream>

template <size_t N>
void metaNumberPrint()
{
	metaNumberPrint<N - 1>();
	std::cout << N << std::endl;
}

template <>
void metaNumberPrint<0>()
{
}

#endif // _META_NUMBER_PRINTER_H_