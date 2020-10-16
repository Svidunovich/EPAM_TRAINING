#include "Employee.h"

Employee::Employee(){
	_name = "";
	_number = 0;
}

void Employee::getData(){
	std::string name;
	std::cout << "Enter name: ";
	std::cin >> name;
	_name = name;
	long number;
	std::cout << "Enter number: ";
	std::cin >> number;
	_number = number;
}

void Employee::putData(){
	std::cout << "Name: " << _name << " | " << "Number: " << _number << "\n\n";
}

