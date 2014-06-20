#ifndef _META_TOWERS_OF_HANOI_H_
#define _META_TOWERS_OF_HANOI_H_

#include <iostream>

template<size_t N, size_t From, size_t To, size_t Spare>
struct MetaTowersOfHanoi
{
	MetaTowersOfHanoi()
	{
		static_assert(From != To && To != Spare && From != Spare, "Disk labels must be different");
		MetaTowersOfHanoi<N - 1, From, Spare, To>();
		std::cout << From << " -> " << To << std::endl;
		MetaTowersOfHanoi<N - 1, Spare, To, From>();
	}
};

template<size_t From, size_t To, size_t Spare>
struct MetaTowersOfHanoi<0, From, To, Spare>
{
	static_assert(From != To && To != Spare && From != Spare, "Disk labels must be different");
};

template<size_t N, size_t From, size_t To, size_t Spare>
void metaTowersOfHanoi()
{
	MetaTowersOfHanoi<N, From, To, Spare>();
}

#endif // _META_TOWERS_OF_HANOI_H_