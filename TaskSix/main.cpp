#include <iostream>
#include <bits/stdc++.h>

template <typename T>
T minNum(T a, T b){
	return a < b ? a : b;
}


template <typename T, int size>
T minStr(T(&array)[size]){
	int count = 0;
	for(int i = 0; i < size; i++){
		for(int j = 1 + i; j < size; j++){
			if(array[i].size() > array[j].size()){
				count = j;
			}
		}	
	}
	return array[count];
}

template <typename T, int size>
T minArray(T(&array)[size]){
	for(int i = 0; i < size; i++){
		for(int j = 1 + i; j < size; j++){
			if(array[i] > array[j]){
				T temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return array[0];
}

/*template <typename T, int size>
T min(const T(&array)[size]){
	return size;
}*/



int main(){
	srand(time(NULL));
	
	std::cout << "Enter the line: " << std::endl;
	std::string str[5];		
	for(int i = 0; i < 5; i++){
		std::cin >> str[i];
	}	
	std::cout << "Minimum line: " << minStr(str) << std::endl; 
	

	std::cout << "Enter numbers: " << std::endl;
	int a, b;
	std::cin >> a >> b;
	std::cout << "Minimum number: " << minNum(a, b) << std::endl;


	int arrInt[5];
	for(int i = 0; i < 5; i++){
		arrInt[i] = rand() % 10;
	}
	std::cout << "Minimum number in an array: " << minArray(arrInt) << "\n\n";
	for(int i = 0; i < 5; i++){
		std::cout << arrInt[i] << std::endl;
	}
	std::cout << std::endl;


	const double fraction = 1.0 / (static_cast<double> (RAND_MAX) + 1.0);
	double arrDouble[5];
	for(int i = 0; i < 5; i++){
		arrDouble[i] = rand() * fraction * 10;
	}
	std::cout << "Minimum number in an array: " << minArray(arrDouble) << "\n\n";
	for(int i = 0; i < 5; i++){
		std::cout << arrDouble[i] << std::endl;
	}
	return 0;
}
