#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int maxint(std::vector<int> &v, int size){
	int max = v[0];	
	int count = 0;
	for(int i = 0; i < size; i++){
		for(int j = i + 1; j < size; j++){
			if(max < v[j]){
				max = v[j];
				count = j;	
			}
		}
	}
	return count + 1;
}

void out(std::vector<int> &v){
	for(int i = 0; i < v.size(); i++){
		std::cout << i + 1 << "# " << v[i] << std::endl;
	}
	std::cout << std::endl;
}

int main(){
	srand(time(NULL));
	std::vector<int> v;
	int n = rand() % 10 + 1;
	std::cout << "Number of array: " << n << std::endl;
	for(int i = 0; i < n; i++){
		int a;
		std::cin >> a;
		v.push_back(a);
	}
	std::cout << std::endl;
	
	out(v);	
	std::cout << "The index of the largest element in the vector: " << maxint(v, v.size()) << std::endl;
	return 0;
}
