#include "File.h"

File::File(const char* filename)
{
	_file.open(filename, std::ios_base::app);
	if(_file.is_open())
	{
		std::cout << "Yes is open" << std::endl;
	}
	std::cout << "file open" << std::endl;
}

File::~File()
{
	_file.close();
	std::cout << "file close" << std::endl;
}
