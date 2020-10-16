#pragma once
#include <iostream>
#include <bits/stdc++.h>

class Institution{
	private:
		std::string _fullName;
		int _age; 
	public:
		Institution();
		Institution(std::string fullName, int age);
		std::string getFullName();
		int getAge();		
		void input(std::string fullName, int age);
		void output();
		~Institution();
};

class School: public Institution{
	private:
		int _totalTeacher;
		int _students; 	
		int _bias;
	public:
		School(int totalTeacher, int students, int bias);
		void out();
		void averageTeacherSchool();
		~School();
};

class College : public Institution{
	private:
		int _totalTeacher;
		int _students;
		int _specialty;
	public:
		College(int totalTeacher, int students, int specialty);
		void out();
		void averageTeacherCollege();
		~College();
};

class University : public Institution{
	private:
		int _totalTeacher;
		int _students;
		int _faculties;
	public:
		University(int totalTeacher, int  students, int faculties);
		void out();
		void averageTeacherUniversity();
		~University();
};
