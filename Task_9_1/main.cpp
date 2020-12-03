#include "Queue.h"
#include "Queue.cpp"

int main()
{
	Queue<int> q;
	/*
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
	*/
	
	std::random_device rd;
	std::default_random_engine engine(rd());
	std::uniform_int_distribution<int> dist {0, 5};
	auto rr = std::bind(dist, engine);
	for(int i = 0; i < 1000; i++)
	{
		q.push(rr());
	}
	std::cout << q.find(4) << std::endl;
	auto t1 = std::chrono::high_resolution_clock::now();
	q.sort();		
	auto t2 = std::chrono::high_resolution_clock::now();
	auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);	
	std::cout << "Sort: " << time_span.count() << std::endl;
	for(int i = 0; i < 1000; i++)
	{
		std::cout << q.front() << "   ";
		q.pop();
	}


	std::vector<int> q2;
	for(int i = 0; i < 1000; i++)
	{
		q2.push_back(rr());
	}
	std::cout << std::endl;
    auto t3 = std::chrono::high_resolution_clock::now();
	std::sort(q2.begin(), q2.end());	
	auto t4 = std::chrono::high_resolution_clock::now();
	auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);	
	std::cout << "std::sort: " << time_span2.count() << std::endl;
	for(auto const &i : q2)
		std::cout << i << "   ";
	std::cout << std::endl;
	return 0;
}
