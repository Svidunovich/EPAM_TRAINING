#include "File.h"

File::File(const char* filename)
{
	_file.open(filename, std::ios_base::app);
	std::cout << "file open" << std::endl;
}

File::~File()
{
	_file.close();
	std::cout << "file close" << std::endl;
}
