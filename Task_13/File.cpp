#include "File.h"

File::File(const char* filename)
{
	_file.open(filename, std::ios_base::app);
}

File::~File()
{
	_file.close();
}
