#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main(){
	srand(time(NULL));
	int random = rand() % 10 + 1;
	std::vector<int> v;
	for(int i = 0; i < random; i++){
		v.push_back(i);
	}	
	for(int i = 0; i < random; i++){
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;

	int k = rand() % 5;
	std::vector<int> v2(v);
	v2.assign(v.begin(), v.end());
	std::cout << "k = " << k << "\n\n";
	for(int i = 0; i < k; i++){
		v2.erase(v2.begin());
		v2.push_back(v2.size() + i + 1);
	}	
	for(int i = 0; i < random; i++){
		std::cout << v2[i] << std::endl;
	}		
	return 0;
}
