#include <iostream>
#include <string>
#include <climits>


int temp(INT_MAX);
int temp2(INT_MAX);

struct Student{
	std::string firstName;
	std::string lastName;
	int score[3];
};


void sort(Student *st, int n){

	for(int i = 0; i < n; i++){
	  for(int k = 1 + i; k < n; k++){
		for(int j = 0; j < 3; j++){		
			if(temp > st[i].score[j]){
				temp = st[i].score[j];
			}
			if(temp2 > st[k].score[j]){
				temp2 = st[k].score[j];
			}	
    	}
		if(temp > temp2){
			Student swp = st[i];
			st[i] = st[k];
			st[k] = swp;
		}
		temp = INT_MAX;
		temp2 = INT_MAX;
  	  }	
	}
}



void output(Student *st, int n)
{
	for(int i = 0; i < n; i++){
		std::cout << "<=============>" << "\n";
		std::cout << "First name: " << st[i].firstName << "\n";
		std::cout << "Last name: " << st[i].lastName << "\n";
	    std::cout << "Score: " << st[i].score[0] << "   " << st[i].score[1] << "   " << st[i].score[2] << "\n";
	}
		std::cout << "<=============>"<< "\n\n";
}



int main(){
	int n;
	std::cout << "Number of elements: ";
	std::cin >> n;
	std::cout << "\n";
	Student *st = new Student[n];
	for(int i = 0; i < n; i++){
		std::cout << "First name: ";
		std::cin >> st[i].firstName;
		std::cout << "Last name: ";
		std::cin >> st[i].lastName;
		std::cout << "Score one: ";
		std::cin >> st[i].score[0];
		std::cout << "Score two: ";
		std::cin >> st[i].score[1];
		std::cout << "Score three: ";
		std::cin >> st[i].score[2];
		std::cout << "\n";
	}
	output(st, n);
	sort(st, n);
	output(st, n);
	delete[] st;
	return 0;
}
