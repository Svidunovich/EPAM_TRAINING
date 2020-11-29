#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>

class String
{
	public:
		String();
		String(const char *str);
		String(const String& copy);
		String(String&& transfer);
		String& operator= (const String& copy);
		String& operator= (String&& transfer);
		~String();
		size_t size() const { return this->_size; };
	private:
		char *_str;
		size_t _size;
};
