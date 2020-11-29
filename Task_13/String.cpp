#include "String.h"

String::String()
	: _str(nullptr), _size(0)
{
	std::cout << "()" << std::endl;
}

String::String(const char *str)
{
	auto length = std::strlen(str);
	this->_size = length;
	this->_str = new char[length];
	std::copy(str, str + length, this->_str);

	std::cout << "const char *str" << std::endl;
}

String::String(const String& copy)
	:	_size(copy._size)
{
	this->_str = new char[this->_size];
	std::copy(copy._str, copy._str + copy._size, this->_str);

	std::cout << "const String& copy" << std::endl;
}

String::String(String&& transfer)
	: _size(transfer._size)
{
	this->_str = transfer._str;
	transfer._str = nullptr;
	transfer._size = 0;

	std::cout << "String&& transfer" << std::endl;
}

String& String::operator= (const String& copy)
{
	if(&copy == this){ return *this; };
	delete this->_str;
	this->_size = copy._size;
	this->_str = new char[this->_size];
	std::copy(copy._str, copy._str + copy._size, this->_str);

	std::cout << "operator= (const String& copy)" << std::endl;
	return *this;
}

String& String::operator= (String&& transfer)
{
	if(&transfer == this){ return *this; };
	delete this->_str;
	this->_str = transfer._str;
	transfer._str = nullptr;
	transfer._size = 0;
	
	std::cout << "operator= (String&& transfer)" << std::endl;
	return *this;
}

String::~String()
{
	delete[] this->_str;

	std::cout << "~String" << std::endl;
}
