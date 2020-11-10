#include "Currency.h"

Currency::Currency()
	: _simb('\0'), _sum(0)
{}

Currency::Currency(char simb, double sum)
	: _simb(simb), _sum(sum)
{}


std::string insertWriteSpace(std::string s)
{
	if(s.size() < 4)
	{
		return s;
	}
	return insertWriteSpace(std::string(s.begin(), s.end() - 3)) + ' ' + std::string(s.end() - 3, s.end());
}

std::ostream& operator<<(std::ostream &out, const Currency& currency)
{
	std::stringstream str;
	std::string temp;
	str << std::setprecision(2) << std::fixed << currency._simb << currency._sum;
	str >> temp;
	std::string tempDesimal = temp.substr(temp.find('.'));
	std::string tempNoDesimal = temp.substr(1, temp.find('.') - 1);

	tempNoDesimal = insertWriteSpace(tempNoDesimal);
	
	return out << currency._simb << tempNoDesimal + tempDesimal;
}

std::istream& operator>> (std::istream &in, Currency& currency)
{
	return in >> currency._simb >> currency._sum;
}

Currency& Currency::operator=(const Currency& currency)
{
	_simb = currency._simb;
	_sum = currency._sum;
	return *this;
}

Currency& Currency::operator+(const Currency& currency)
{
	if(_simb == currency._simb)
	{
		_sum = _sum + currency._sum;
	}	
	else 
	{
		std::cout << "Another currency" << std::endl;
	}	
	return *this;
}

Currency& Currency::operator-(const Currency& currency)
{
	if(_simb == currency._simb)
	{
		_sum = _sum - currency._sum;
	}
	else
	{
		std::cout << "Another currency" << std::endl;
	}
	return *this;
}
