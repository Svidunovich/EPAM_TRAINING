#pragma once
#include <iostream>
#include <bits/stdc++.h>

class Array{
	private:
		double **arr;
		int _str;
		int _size;
	public:
		Array();
		Array(int str, int size);
		void output();
		void out();
		int getStr();
		int getSize();
		double getArr(int i, int j);
		~Array();
};

void sumStr(Array &array);
