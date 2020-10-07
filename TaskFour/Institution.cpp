#include "Institution.h"

Institution::Institution(std::string fullName, int age){
	_fullName = fullName;
	_age = age;
}
Institution::Institution(){
	_fullName = "None";
	_age = 0;
}

Institution::~Institution(){
	_fullName;
	_age;
}

std::string Institution::getFullName(){ return _fullName; }
int Institution::getAge(){ return _age; }

void Institution::output(){
	std::cout << "Name: " << _fullName << " Age: " << _age << std::endl;
}

void Institution::input(std::string fullName, int age){
	_fullName = fullName;
	_age = age;	
}


School::School(int totalTeacher, int students, int bias){
	_totalTeacher = totalTeacher;
	_students = students;
	_bias = bias;
}

void School::out(){
	std::cout << "Total teachers in the school: " << _totalTeacher << " Number of Students: " << _students << " Total bias: " << _bias <<  std::endl;
}

void School::averageTeacherSchool(){
	std::cout << "Average number of students per teacher in the school: " << static_cast<double>(_students) / _totalTeacher << std::endl;
}

School::~School(){
	_totalTeacher;
	_students;
	_bias;
}

College::College(int totalTeacher, int students, int specialty){
	_totalTeacher = totalTeacher;
	_students = students;
	_specialty = specialty;
}

void College::out(){
	std::cout << "Total teachers in the college: " << _totalTeacher << " Number of Students: " << _students << " Total specialty: " << _specialty << std::endl;
}

void College::averageTeacherCollege(){
	std::cout << "Average number of students per teacher in the school: " << static_cast<double>(_students) / _totalTeacher << std::endl;
}

College::~College(){
	_totalTeacher;
	_students;
	_specialty;
}

University::University(int totalTeacher, int students, int faculties){
	_totalTeacher = totalTeacher;
	_students = students;
	_faculties = faculties;
}

void University::out(){
	std::cout << "Total teachers in the university: " << _totalTeacher << " Number of Students: " << _students << " Total faculties: " << std::endl;
}

void University::averageTeacherUniversity(){
	std::cout << "Average number of students per teacher in the university: " << static_cast<double>(_students) / _totalTeacher << std::endl;
}

University::~University(){
	_totalTeacher;
	_students;
	_faculties;
}
