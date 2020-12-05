#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>

class Student
{
	public:
		Student();
		Student(const Student& copy);
		Student(Student&& transfer);
		Student& operator= (const Student& copy);
		Student& operator= (Student&& transfer);
		~Student();
		friend std::ostream& operator<<(std::ostream &out, const Student& student);
		friend std::istream& operator>>(std::istream &in, Student& student);
		struct ageGreater
		{
			bool operator()(const Student& x, const Student& y) const
			{
					return (x._age < y._age);
			}
		};
		struct courseGreater
		{
			bool operator()(const Student& x, const Student& y) const
				{
					return (x._course < y._course);
				}
		};
		//	bool operator()(const Student& x, const Student& y) const;
	private:
		std::string _fullName;	
		int _age;
		int _course;
		std::string _group;
};


