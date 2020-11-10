#include "Text.h"

void Menu(std::vector<Text> &text)
{
	std::cout << "1 - Download data from file" << std::endl;
	std::cout << "2 - Enter data" << std::endl;
	std::cout << "3 - Add data on file" << std::endl;
	std::cout << "4 - Sort database by alphabet" << std::endl;
	std::cout << "5 - Sort database by age" << std::endl;
	std::cout << "6 - Output: list of people, born on given month" << std::endl;
	std::cout << "7 - Output: last name oldest peolpe" << std::endl;
	std::cout << "8 - Output: Whole last name, beginning by given letter" << std::endl;
	std::cout << "0 - Exit program" << std::endl;
	int i;
	std::cout << "Enter your choise: ";
	std::cin >> i;
	switch(i)
	{
		case 1:
			setDataFile(text);
			std::cout << std::endl;
			return Menu(text);
			break;
		case 2:
			enterNewMember(text);		
			std::cout << std::endl;
			return Menu(text);
			break;
		case 3:
			createDataFile(text);
			std::cout << std::endl;
			return Menu(text);
			break;
		case 4:
			sortAlphabet(text);
			std::cout << std::endl;
			return Menu(text);
			break;
		case 5:
			sortAge(text);
			std::cout << std::endl;
			return Menu(text);
			break;
		case 6:
			monthBirth(text);
			std::cout << std::endl;
			return Menu(text);
			break;
		case 7:
			findOld(text);
			std::cout << std::endl;
			return Menu(text);
			break;
		case 8:
			letterOut(text);
			std::cout << std::endl;
			return Menu(text);
			break;
		case 0:
			return;
			break;
		default:
			return Menu(text);
			std::cout << std::endl;
			break;		
	}
}


int main(){
	std::vector<Text> txt;
	Menu(txt);	
	return 0;
}
