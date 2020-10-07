#include "vector.h"


int main(){
	double *num1 = new double[10];
	double *num2 = new double[10];
	double	a; 
	std::cout << "Input first array: " << "\n"; 
	for(int i = 0; i < 10; i++){
		std::cin >> a;
		num1[i] = a;
	}
	std::cout << std::endl;
	Vector array1(num1, 10);
	array1.sort();
	array1.output();
	array1.min();
	array1.max();
	array1.middle();
	std::cout << "Input second array: " << "\n";
	for(int i = 0; i < 10; i++){
		std::cin >> a;
		num2[i] = a;
	}
	Vector array2(num2, 10);
	array2.searchSum();
	return 0;
}

