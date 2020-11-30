#pragma once
#include <iostream>
#include <fstream>

class File
{
	private:
		File();
		File(const char* filename);
		~File();
	public:
		std::fstream _file;
};
