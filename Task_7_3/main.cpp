#include "Employee.h"

int main(){
	int n;
	std::cout << "Enter amount until 100: ";
	std::cin >> n;
	std::vector<Employee> worker(n);
	for(int i = 0; i < worker.size(); i++){
		worker[i].getData();
		std::cout << std::endl;
	}
	for(int i = 0; i < worker.size(); i++){
		worker[i].putData();
	}

	return 0;
}
