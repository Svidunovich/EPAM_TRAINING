#pragma once 
#include <iostream>
#include <algorithm>
#include <climits>

class Vector{
	private:
		double *d_num;
		int m_length;	
	public:
		Vector(double num[], int size);
		Vector(int size);
		Vector();
		void searchSum();
		void sort();
		void min();
		void max();
		void middle();
		void output();
		~Vector(){
			delete[] d_num;
		}
};



