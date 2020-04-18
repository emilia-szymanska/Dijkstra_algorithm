#ifndef PAIR_HH
#define PAIR_HH


template <typename T>
struct Pair
{
	T first;
	T second;
	Pair(T element1 = T(0), T element2 = T(0)) {first = element1; second = element2;};
	bool operator > (Pair<T> pair_to_compare);
	bool operator < (Pair<T> pair_to_compare);
};

#include "../src/Pair.cpp"

#endif 
