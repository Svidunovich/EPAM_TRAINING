#include <iostream>
#include <queue>
#include <algorithm>


template <typename T>
class Queue : public std::queue<T>
{
	public:
	T& operator[](size_t index);
};

template <typename T>
T& Queue<T>::operator[](size_t index)
	{		
		std::queue<T> q;
		std::queue<T> w;
		auto size1 = this->size();
		for(int i = 0; i < size1; ++i)
		{
			q.push(this->front());
			this->pop();
		}
		for(size_t i = 0; i < index; i++)
		{
				this->push(q.front());	
				q.pop();
		}
		auto size2 = q.size();
		w.push(q.front());
		for(size_t i = 0; i < size2; ++i)
		{
			this->push(q.front());
			q.pop();
		}
		q.push(w.front());
		return q.front();
	}

int main()
{
	Queue<int> v;
	for(int i = 0; i < 5; ++i)
	{
		v.push(i);
	}
	for(size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << "   ";
	}
	std::cout << std::endl;
	auto out = [&v]()
	{
		auto size = v.size();
		for(size_t i = 0; i < size; ++i)
		{
			std::cout << v.front() << std::endl;
			v.pop();
		}
	};
	out();
	return 0;
}
