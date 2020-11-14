#include "Text.h"

int Text::id = 0;

void Menu(std::vector<Text> &text)
{
	std::cout << "1 - Download data from file" << std::endl;
	std::cout << "2 - Enter data" << std::endl;
	std::cout << "3 - Create file" << std::endl;
	std::cout << "4 - Sort database by alphabet" << std::endl;
	std::cout << "5 - Sort database by age" << std::endl;
	std::cout << "6 - Output: list of people, born on given month" << std::endl;
	std::cout << "7 - Output: last name oldest peolpe" << std::endl;
	std::cout << "8 - Output: all surnames, starting with a given letter" << std::endl;
	std::cout << "9 - All peoples" << std::endl;
	std::cout << "0 - Exit program" << std::endl;
	int i;
	std::cout << "Enter your choise: ";
	std::cin >> i;
	system("clear");
	switch(i)
	{
		case 1:
			setDataFile(text);
			std::cout << std::endl;
			break;
		case 2:
			enterData(text);
			std::cout << std::endl;
			break;
		case 3:
			createDataFile(text);
			std::cout << std::endl;
			break;
		case 4:
			sortAlphabet(text);
			std::cout << std::endl;
			break;
		case 5:
			sortAge(text);
			std::cout << std::endl;
			break;
		case 6:
			monthBirth(text);
			std::cout << std::endl;
			break;
		case 7:
			findOld(text);
			std::cout << std::endl;
			break;
		case 8:
			letterOut(text);
			std::cout << std::endl;
			break;
		case 9:
			outAll(text);
			std::cout << std::endl;
			break;
		case 0:
			return;
			break;
		default:
			std::cout << std::endl;
			break;		
	}
	return Menu(text);
}

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
	std::ifstream file("data.txt");
	for(int i = 0; i < text.size(); i++)
	{
		getline(file, text[i]._fullName);
		getline(file, text[i]._fullName);
		getline(file, text[i]._numberBirth);
		getline(file, text[i]._monthBirth);
		getline(file, text[i]._yearBirth);
		getline(file, text[i]._gender);
	}
	file.close();
}

Text& Text::out()
{
	std::cout << _fullName << " " << _numberBirth << " " << _monthBirth << " " << _yearBirth << " " << _gender <<  std::endl;	
	return *this;
}

void createDataFile(std::vector<Text> &text)
{
	std::ofstream fout("data.txt");
	fout.close();
}

void monthBirth(std::vector<Text> &text)
{
	std::string month;
	std::cout << "Enter month: ";
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

void enterData(std::vector<Text> &text)
{
	Text temp;
	text.push_back(temp);
	std::string str;
	std::ofstream file("data.txt", std::ios_base::app);
	
	for(int i = 0; i < 6; i++)
	{
		std::getline(std::cin, str);	
		file << str << "\n";	
	}
	file.close();
}
