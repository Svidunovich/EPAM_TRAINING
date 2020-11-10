#include "Text.h"

int Text::id = 0;

/*
void Menu(std::vector<Text> &text)
{
	std::cout << "1 - Download data from file" << std::endl;
	std::cout << "2 - Enter data" << std::endl;
	std::cout << "3 - Add data" << std::endl;
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
			return Menu(text);
			break;
		case 2:
			enterNewMember(text);		
			return Menu(text);
			break;
		case 3:
			setDataFile(text);
			return Menu(text);
			break;
		case 4:
			sortAlphabet(text);
			return Menu(text);
			break;
		case 5:
			sortAge(text);
			return Menu(text);
			break;
		case 6:
			monthBirth(text);
			return Menu(text);
			break;
		case 7:
			findOld(text);
			return Menu(text);
			break;
		case 8:
			letterOut(text);
			return Menu(text);
			break;
		case 0:
			return;
			break;
		default:
			return Menu(text);
			break;		
	}
}
*/

bool fexists(std::string str)
{
	std::ifstream ifile(str);
	bool tt;
	if(ifile){ tt = 1; } else { tt = 0; }
	ifile.close();
	return tt;
}

Text::Text(std::string fullName, std::string numberBirth, std::string monthBirth, std::string yearBirth, std::string gender)
   	: _fullName(fullName), _numberBirth(numberBirth), _monthBirth(monthBirth), _yearBirth(yearBirth), _gender(gender), _number(id++)
	{}

Text::Text()
   	: _fullName(""), _numberBirth(""), _monthBirth(""), _yearBirth(""), _gender(""), _number(id++) 
	{}

void setDataFile(std::vector<Text> &text)
{
	std::getline(std::cin, text[0]._fullName);
	for(int i = 0; i < text.size(); ++i)
	{
		std::stringstream dataName;
		dataName << "datafile" << text[i]._number << ".txt";
		std::string name;
		dataName >>  name;
		if(fexists(name)){
		std::ifstream file(name);
		getline(file, text[i]._fullName);
		getline(file, text[i]._numberBirth);
		getline(file, text[i]._monthBirth);
		getline(file, text[i]._yearBirth);
		getline(file, text[i]._gender);
		file.close();	
		}
	}
}

Text& Text::out()
{
	std::cout << _fullName << " " << _numberBirth << " " << _monthBirth << " " << _yearBirth << " " << _gender <<  std::endl;	
	return *this;
}

void createDataFile(std::vector<Text> &text)
{
	Text newMember;
	text.push_back(newMember);
	std::stringstream dataName;
	dataName << "datafile" << text[text.size() - 1]._number << ".txt";
	std::string name;
	dataName >>  name;
	std::getline(std::cin, newMember._fullName);
	std::ofstream fout(name);
	std::vector<std::string> data;
	for(int i = 0; i < 5; i++)
	{
		switch(i){
			case 0:
				std::cout << "Enter full name: ";
				break;
			case 1:
				std::cout << "Enter day of birth: ";
				break;
			case 2:
				std::cout << "Enter month of birth: ";
				break;
			case 3:
				std::cout << "Enter year of birth: ";
				break;
			case 4:
				std::cout << "Enter your gender: ";
				break;
		}
		std::string str;
		std::getline(std::cin, str);
		data.push_back(str);	
	}
	fout << data[0] << "\n" << data[1]<< "\n" << data[2] << "\n" << data[3] << "\n" << data[4] << std::endl << std::endl;
	fout.close();
}

void monthBirth(std::vector<Text> &text)
{
	std::string month;
	std::cout << "Enter month: " << std::endl;
	std::getline(std::cin, month);
	std::getline(std::cin, month);
	std::cout << "Born at this month: " << std::endl;
	for(int i = 0; i < text.size(); i++)
	{
		if(text[i]._monthBirth == month)
		{
			text[i].out();
		}
	}
}

void sortAge(std::vector<Text> &text)
{
	for(int i = 0; i < text.size() - 1; i++)
	{	
		for(int j = 1 + i; j < text.size(); j++)
		{
			int numi = stoi(text[i]._yearBirth, nullptr, 10);
			int numj = stoi(text[j]._yearBirth, nullptr, 10);
			if(numi < numj)
			{
				Text temp = text[i];
				text[i] = text[j];
				text[j] = temp;
			}
			else if(numi == numj)
			{
				int numim = stoi(text[i]._monthBirth, nullptr, 10);
				int numjm = stoi(text[j]._monthBirth, nullptr, 10);
				if(numim < numjm)
				{
					Text temp = text[i];
					text[i] = text[j];
					text[j] = temp;
				}
				else if(numim == numjm)
				{
					int numin = stoi(text[i]._numberBirth, nullptr, 10);
					int numjn = stoi(text[j]._numberBirth, nullptr, 10);
					if(numin < numjn)
					{
						Text temp = text[i];
						text[i] = text[j];
						text[j] = temp;
					}
				}
			}
		}
	}
}

void outAll(std::vector<Text> &text)
{
	std::cout << "----------------------------------" << std::endl;
	for(auto const &i : text)
		std::cout << i._fullName << " " << i._numberBirth << " " << i._monthBirth << 	" " << i._yearBirth << " " << i._gender <<  std::endl;	
	std::cout << "----------------------------------" << std::endl;
}

void findOld(std::vector<Text> &text)
{
	Text temp2 = text[0];
		for(int j = 1; j < text.size(); j++)
		{
			int numi = stoi(temp2._yearBirth, nullptr, 10);
			int numj = stoi(text[j]._yearBirth, nullptr, 10);
			if(numi > numj)
			{
				temp2 = text[j];
			}
			else if(numi == numj)
			{
				int numim = stoi(temp2._monthBirth, nullptr, 10);
				int numjm = stoi(text[j]._monthBirth, nullptr, 10);
				if(numim > numjm)
				{
					temp2 = text[j];
				}
				else if(numim == numjm)
				{
					int numin = stoi(temp2._numberBirth, nullptr, 10);
					int numjn = stoi(text[j]._numberBirth, nullptr, 10);
					if(numin > numjn)
					{
						temp2 = text[j];
					}
				}
			}
		}
		std::cout << "----------------------------" << std::endl;
		std::cout << "Oldest person: " << temp2._fullName << " " << temp2._numberBirth <<
		" " << temp2._monthBirth << " " << temp2._yearBirth << " " << temp2._gender << std::endl;
		std::cout << "----------------------------" << std::endl;
}

void letterOut(std::vector<Text> &text)
{
	char letter;
	std::cout << "Letter: ";
	std::cin >> letter;
	std::cout << "---------------------------------------" << std::endl;
	for(auto i = 0; i < text.size(); ++i)
	{
		if((char)tolower(text[i]._fullName[0]) == tolower(letter))
		{
			text[i].out();	
		}
	}
	std::cout << "---------------------------------------" << std::endl;
}

void sortAlphabet(std::vector<Text> &text)
{
	for(int i = 0; i < text.size() - 1; ++i)
	{
		std::stringstream ss1;
		std::string str1;
		ss1 << text[i]._fullName;
		ss1 >> str1;
		for(int j = i + 1; j < text.size(); ++j)
		{
			std::stringstream ss2;
			std::string str2;
			ss2 << text[j]._fullName;
			ss2 >> str2;
			if(str1 > str2)
			{
				Text temp = text[i];
				text[i] = text[j];
				text[j] = temp;
			}
		}
	}
}

Text& Text::enterData()
{
	std::cout << "Enter full name: ";
	std::getline(std::cin, _fullName);
	std::getline(std::cin, _fullName);
	std::cout << "Enter day of birth: ";
	std::getline(std::cin, _numberBirth);
	std::cout << "Enter month of birth: ";
	std::getline(std::cin, _monthBirth);
	std::cout << "Enter year of birth: ";
	std::getline(std::cin, _yearBirth);
	std::cout << "Enter your gender: ";
	std::getline(std::cin, _gender);
	return *this;
}

void enterNewMember(std::vector<Text> &text)
{
	Text data;
	data.enterData();
	text.push_back(data);
}

