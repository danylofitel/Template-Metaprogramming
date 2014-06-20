#ifndef _META_BUBBLE_SORT_H_
#define _META_BUBBLE_SORT_H_

template<class T, int Size, int Index>
class MetaBubbleSortLoop
{
private:
	enum { go = (Index <= Size - 2) };
public:
	static void loop(T * data)
	{
		if (data[Index] > data[Index + 1])
		{
			T temp = data[Index];
			data[Index] = data[Index + 1];
			data[Index + 1] = temp;
		}
		MetaBubbleSortLoop<T, go ? Size : 0, go ? (Index + 1) : 0>::loop(data);
	}
};

template<class T>
class MetaBubbleSortLoop<T, 0, 0>
{
public:
	static void loop(T * data)
	{
	}
};

template<class T, int N>
class MetaBubbleSort
{
	static_assert(N > 0, "Array size has to be positive");
public:
	static void sort(T * data)
	{
		MetaBubbleSortLoop<T, N - 1, 0>::loop(data);
		MetaBubbleSort<T, N - 1>::sort(data);
	}
};

template<class T>
class MetaBubbleSort<T, 1>
{
public:
	static void sort(T * data)
	{
	}
};

#endif // _META_BUBBLE_SORT_H_