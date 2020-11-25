#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <functional>

struct Student
{
	std::string _firstName;
	std::string _lastName;
	std::string _faculty;
	int _group;
	std::string _email;
};

int main()
{
	std::vector<std::string> firstName = { "Sasha", "Lesha" , "Maxim" , "Yaroslav" , "Adelina" };
	std::vector<std::string> lastName = { "Svidunovich" , "Starovoitov" , "Zhuchick", "Kohovets" ,"Boltrushko" };
	std::vector<std::string> faculty = { "FizMat", "FilFac", "SportFac", "BioFac" , "IstFac" };
	std::vector<int> group = { 1, 2, 3, 4, 5 };
	std::vector<std::string> email = { "aaa@gmail.com" , "bbb@gmail.com" , "ccc@gmail.com" , "ddd@gmail.com" , "eee@gmail.com" };
	std::default_random_engine engine(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> dist{ 0 , 4 };
	auto rr = std::bind(dist, engine); 
	Student students1[30];
	Student *students2 = new Student;
	for(auto i = 0; i < 30; i++)
	{
		students1[i]._firstName = firstName[rr()];
		students1[i]._lastName = lastName[rr()];
		students1[i]._faculty = faculty[rr()];
		students1[i]._group = group[rr()];
		students1[i]._email = email[rr()];
	}
	for(auto i = 0; i < 30; i++)
	{
		std::cout << i+1 << "#\t" << students1[i]._firstName << "   " << students1[i]._lastName << "\t" 
		<< students1[i]._faculty << "   " << students1[i]._group << "\t" << students1[i]._email << std::endl;
	}	
	std::cout << std::endl << std::endl;
	std::cout << (*students1)._firstName << "   " << (*students1)._lastName << std::endl;
	std::cout << "Memory students1: " << sizeof(students1) << "  |  Memory students2: " << sizeof(students2) << std::endl << std::endl;
	for(auto i = 0; i < 30; i++)
	{
		std::cout << i << "#\t" << (students1+i)->_firstName << "   " << (students1+i)->_lastName << "   " << (students1+i)->_faculty << "   " << (students1+i) << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Iter: " <<  sizeof(*students1) << std::endl << std::endl;
	std::cout << "Places: " << &(students1->_firstName) << "   " << &(students1->_lastName) << "   " << &(students1->_faculty) << "   " << &(students1->_group) << "   " << &(students1->_email) << std::endl; 
std::cout << "Places: " << &((students1+1)->_firstName) << "   " << &((students1+1)->_lastName) << "   " << &((students1+1)->_faculty) << "   " << &((students1+1)->_group) << "   " << &((students1+1)->_email) << std::endl; 
	std::cout << std::endl << std::endl;
	std::cout << sizeof(std::string);
	return 0;
}
