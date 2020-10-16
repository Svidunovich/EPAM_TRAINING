#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



void out(std::vector<int> &v){
	for(int i = 0; i < v.size(); i++){
		std::cout << v[i] << std::endl;
	}
	std::cout << std::endl;
}

int main(){
	srand(time(NULL));
	std::vector<int> v;
	int n = rand() % 10;
	std::cout << "Number of array: " << n << std::endl;
	for(int i = 0; i < n; i++){
		int a;
		std::cin >> a;
		v.push_back(a);
	}
	std::cout << std::endl;
	out(v);	
	return 0;
}
