#include "Employee.h"

Employee::Employee(){
		
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
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Number: " << _number << "\n\n";
}
