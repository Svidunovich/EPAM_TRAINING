#ifndef ALGORITHM_H
#define ALGORITHM_H

template <typename T, typename U>
T myFind(T&& a, T&& b, U&& c)
{
	while(a != b)
	{
		if(*a == c)
			return a;
		a++;
	}
	return b;
}

#endif
