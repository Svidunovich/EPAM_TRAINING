#include "Array.h"

Array::Array(int str, int size){
	_str = str;
	_size = size;
	srand(time(NULL));
	arr = new double* [str];
	for(int i = 0; i < str; i++){
		arr[i] = new double [size];	
	}	
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	for(int i = 0; i < str; i++){
		for(int j = 0; j < size; j++){
			arr[i][j] = (rand() * fraction * 10);
		}
	}
}

void Array::output(){
	for(int i = 0; i < _str; i++){
		for(int j = 0; j < _size; j++){
			std::cout << arr[i][j] << "    ";
		}
		std::cout << std::endl;
	}
}


Array::~Array(){
	for(int i = 0; i < _str; i++){
		delete[] arr[i];
	}
	delete[] arr;
}

int Array::getStr(){
	return _str;
}

int Array::getSize(){
	return _size;
}

double Array::getArr(int i, int j){
	return arr[i][j];
}

void sumStr(Array &array){
	srand(time(NULL));
	int a = rand() % (10 * array.getSize());
	int count = 0;
	int sum = 0;
	std::cout << "Special number: " << a << std::endl;
	for(int i = 0; i < array.getStr(); i++){
		for(int j = 0; j < array.getSize(); j++){
			sum += array.getArr(i, j);
		}
		if(sum > a){
			count++;
		}
		sum = 0;
	}
	std::cout << "Number of lines is greater than the specified value: " << count << std::endl;

}
