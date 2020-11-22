#include "Queue.h"

int main()
{
	Queue<int> q;
	q.push(123);
	std::cout << q.front() << std::endl;
	q.push(111);
	q.push(222);
	std::cout << q.front() << "   " << q.back() << "   " << q.size() << std::endl;
	q.pop();
	std::cout << q.front() << "   " << q.back() << "   " << q.size() << std::endl;
	q.pop();
	q.pop();
	if(q.empty())
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		std::cout << "not empty" << std::endl;
	}
	return 0;
}
