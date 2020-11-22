#include "Queue.h"
#include "Queue.cpp"

int main()
{
	Queue<int> q;
	q.push(10);
	q.push(5);
	std::cout << q.back() << "   " << q.front() << std::endl;
	q.pop();
	q.push(30);
	std::cout << q.back() << "   " << q.front() << std::endl;
	q.pop();
	q.pop();
	if(q.empty() == 0)
	{
		std::cout << "not empty" << std::endl;
	}
	else
	{
		std::cout << "empty" << std::endl;
	}
	return 0;
}
