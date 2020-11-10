#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

class Currency{
	private:
		char _simb;
		double _sum;
	public:
		Currency();
		Currency(char simb, double sum);
		friend std::ostream& operator<<(std::ostream &out, const Currency& currency);
		friend std::istream& operator>>(std::istream &in, Currency& currency);
		Currency& operator=(const Currency& currency);
		Currency& operator+(const Currency& currency);
		Currency& operator-(const Currency& currency);
};
