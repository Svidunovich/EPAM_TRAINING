#include "String.h"

int main()
{
	String str1;
	String str2("Yaroslav");
	String str3(str2);
	String str4(std::move(str2));
	str1 = str4;
	str1 = "Privet";
	return 0;
}
