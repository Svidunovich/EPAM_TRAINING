#include <iostream>
#include <string>
#include <climits>


int temp;

struct Student{
	std::string firstName;
	std::string lastName;
	int score[3];
};

int min(Student *st, int i){
	if(st[i].score[0] < st[i].score[1] && st[i].score[0] < st[i].score[2]){
		temp = st[i].score[0];
	} else if (st[i].score[1] < st[i].score[0] && st[i].score[1] < st[i].score[2]){
		temp = st[i].score[1];
	} else {
		temp = st[i].score[2];
	}
	return temp;
}

void sort(Student *st, int n){

	for(int i = 0; i < n; i++){
		for(int j = 1 + i; j < n; j++){
		if(min(st, i) > min(st, j)){
			Student swp = st[i];
			st[i] = st[j];
			st[j] = swp;
		}
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
