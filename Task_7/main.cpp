#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){
	srand(time(NULL));
	std::vector<int> v;
	//task 1
	//
	//
	auto in = [&v](){
		for(int i = 0; i < 10; i++){
			v.push_back(rand() % 10);
		}	
	};
	in();
	auto out = [&v](){
		for(int i = 0; i < 10; i++){
			std::cout << v[i] << "  ";			
		}
		std::cout << std::endl;
	};
	out();
	//task 2
	//
	//
	int count = 0;
	auto sort = [&v, &count](){
		for(int i = 0; i < v.size(); i++){
			for(int j = 1 + i; j < v.size(); j++){
				if(v[i] > v[j]){
					std::swap(v[i], v[j]);
					count++;
				}
			}
		}
	};
	sort();
	out();
	std::cout << "Number of permutations: " << count << std::endl;
	std::cout << "\n";
	//task 3
	//
	//
	std::string str{"aaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccc"};
	auto findInput = [&str](){
		int temp = 0;
		std::cout << str << std::endl;
		std::string str2;		
		std::cin >> str2;
		for(int i = 0; i < str.size(); i++){
			if(str2[0] == str[i]){
				for(int j = 1; j < str2.size(); j++){
					if(str2[j] == str[i + j]){
						temp++;
					} 
				   if(temp + 1 == str2.size())	{
						break;
				   } 
				}
			}	
			if(temp + 1 == str2.size()){
				break;
			} else {
				temp = 0;
			}
		}
		if(temp != 0){
			std::cout << "String found" << "\n\n";
		} else {
			std::cout << "String not found" << "\n\n";
		}
	};
	findInput();
	/*	
	auto findInputIter = [&str](){
		std::cout << str << std::endl;
		std::string str2;		
		std::cin >> str2;
		int temp = str2.size() - 1;
		std::string::iterator it;
		it = std::search(str.begin(), str.end(), str2, str2+temp);
		if(it != str.end()){
			std::cout << "String found at position: " << (it-str.begin()) << "\n\n";
		} else {
			std::cout << "String not found" << "\n\n";
		}
	};
	findInputIter();
	*/	
	return 0;	
}
