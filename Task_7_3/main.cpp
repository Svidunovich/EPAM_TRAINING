#include "Employee.h"

int main(){
	int n;
	std::cout << "Enter amount under 100: ";
	std::cin >> n;
	std::cout << std::endl;
	std::vector<Employee> rab(n);
	for(int i = 0; i < rab.size(); i++){
		rab[i].getData();
		std::cout << std::endl;
	}	
	std::cout << "\n\n";
	for(int i = 0; i < rab.size(); i++){
		rab[i].putData();
		std::cout << "\n";
	}
	return 0;
}
