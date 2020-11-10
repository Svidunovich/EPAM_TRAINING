#include "Currency.h"

int main()
{
	Currency d1('$', 222.22);
	Currency d2('$', 111.11);
	Currency dl3;
	std::cin >> dl3;
	std::cout << dl3 << std::endl;
	std::cout << d1 + d2 << std::endl;
	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	return 0;
}
