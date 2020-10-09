#include "Array.h"


int main(){
	srand(time(NULL));
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	double *arrDouble = new double[10];
	for(int i = 0; i < 10; i++){
		arrDouble[i] = rand() * fraction * 100;
	}

	int *arrInt = new int[10];
	for(int i = 0; i < 10; i++){
		arrInt[i] = rand() % 100;
	}

	Array<int> arrayInt(arrInt, 10);
	arrayInt.sort();
	arrayInt.out();
	std::cout << std::endl;

	Array<double> arrayDouble(arrDouble, 10);
	arrayDouble.sort();
	arrayDouble.out();
	return 0;
}
