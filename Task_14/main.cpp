#include "Student.h"
#include "Ptr.h"

int main()
{

	
	Ptr<Student> d(new Student);
	std::vector<Student> v(3);
	for(size_t i = 0; i < 3; i++)
	{
		std::cin >> *d;
		v[i] = *d;
	}	
	std::sort(v.begin(), v.end(), Student::courseGreater());

	for(unsigned i = 0; i < 3; i++)
	{
		std::cout << v[i] << std::endl;
	}
	
	
	/*
	Ptr<int> i(new int);
	std::cin >> *i;
	Ptr<int> q;
	q = i;
	std::cout << *q;
	*/
	return 0;
}
