#include "Student.h"

Student::Student()
	: _fullName(std::string()), _age(int()), _course(int()), _group(std::string())
{
	std::cout << "()" << std::endl;
}

Student::Student(const Student& copy)
	: _fullName(copy._fullName), _age(copy._age), _course(copy._course), _group(copy._group)
{
	std::cout << "const Student& copy" << std::endl;
}

Student::Student(Student&& transfer)
	: _fullName(transfer._fullName), _age(transfer._age), _course(transfer._course), _group(transfer._group)
{
	transfer._fullName = std::string();
	transfer._age = int();
	transfer._course = int();
	transfer._group = std::string();

	std::cout << "Student&& transfer" << std::endl;
}

Student& Student::operator=(const Student& copy)
{
	if(&copy == this)
		return *this;
	this->_fullName = copy._fullName;
	this->_age = copy._age;
	this->_course = copy._course;
	this->_group = copy._group;

	
	std::cout << "operator=(const Student& copy)" << std::endl;
	return *this;
}

Student& Student::operator=(Student&& transfer)
{
	if(&transfer == this)
		return *this;
	this->_fullName = transfer._fullName;
	this->_age = transfer._age;
	this->_course = transfer._course;
	this->_group = transfer._group;
	
	transfer._fullName = std::string();
	transfer._age = int();
	transfer._course = int();
	transfer._group = std::string();

	std::cout << "operator=(Student&& transfer)" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Student& student)
{
	out << "Full name: " << student._fullName << "   Age: " << student._age << "   Course: "
		<< student._course << "   Group: " << student._group;
	return out;
}

std::istream& operator>>(std::istream &in, Student& student)
{
	return in >> student._fullName >> student._age >> student._course >> student._group;
}

/*
bool Student::operator()(const Student& x, const Student& y) const
{
	return (x._age < y._age);
}
*/

Student::~Student()
{
	std::cout << "~Student" << std::endl;
}


