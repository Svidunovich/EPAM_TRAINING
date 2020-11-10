#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

class Text{
	private:
		std::string _fullName;
		std::string _numberBirth;
		std::string _monthBirth;
		std::string _yearBirth;
		std::string _gender;
		int _number;
		static int id;
	public:
		Text(std::string fullName, std::string numberBirth, std::string monthBirth, std::string yearBirth, std::string gender);
		Text();
		Text& enterData();
		Text& out();
		friend void setDataFile(std::vector<Text> &text);
		friend void createDataFile(std::vector<Text> &text);
		friend void monthBirth(std::vector<Text> &text);
		friend void sortAge(std::vector<Text> &text);
		friend void outAll(std::vector<Text> &text);
		friend void findOld(std::vector<Text> &text);
		friend void letterOut(std::vector<Text> &text);
		friend void sortAlphabet(std::vector<Text> &text);
		friend void enterNewMember(std::vector<Text> &text);
};
