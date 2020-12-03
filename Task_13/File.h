#pragma once
#include <iostream>
#include <fstream>

class File
{
	public:
		File();
		File(const char* filename);
		~File();
	private:
		std::fstream _file;
};
