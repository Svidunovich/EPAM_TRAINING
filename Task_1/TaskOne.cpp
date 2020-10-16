#include <iostream>
#include <bits/stdc++.h>


int temp;
int temp2;

struct student{
	std::string firstName;
	std::string	lastName;
	int score[3];	
};


void sort(student *st, int n){
	for(int i = 0; i < n - 1; i++){
			if(st[i].score[0] < st[i].score[1] && st[i].score[0] < st[i].score[2]){
				temp = st[i].score[0];
			} else if(st[i].score[1] < st[i].score[0] && st[i].score[1] < st[i].score[2]){
				temp = st[i].score[1];
			} else {
				temp = st[i].score[2];
			}
				if(st[i + 1].score[0] < st[i + 1].score[1] && st[i + 1].score[0] < st[i + 1].score[2]){
				temp2 = st[i].score[0];
			} else if(st[i + 1].score[1] < st[i + 1].score[0] && st[i + 1].score[1] < st[i + 1].score[2]){
				temp2 = st[i + 1].score[1];
			} else {
				temp2 = st[i + 1].score[2];
			}
				if(temp > temp2){
					student asd = st[i];
					st[i] = st[i + 1];
					st[i + 1] = asd;	
				}
	}
	for(int i = 0; i < n; i++){
		std::cout << "-------------------------------------" << "\n";
		std::cout << "First Name = " << st[i].firstName << "\n";
		std::cout << "Last Name = "<< st[i].lastName << "\n";
		std::cout << "Score One = "<< st[i].score[0] << "\n";
		std::cout << "Score Two = "<< st[i].score[1] << "\n";
		std::cout << "Score Three = "<< st[i].score[2] << "\n";
		std::cout << "\n";
		std::cout << "---------------------------------------" << "\n";

	}	
	
}



int main(){
	int n;
	std::cout << "Numbers of elements = ";
	std::cin >> n;	
	student *st = new student[5];
	for(int i = 0; i < n; i++){
		std::cout << "first Name = ";
		std::cin >> st[i].firstName;
		std::cout << "lats Name = ";
		std::cin >> st[i].lastName;
		std::cout << "score one = ";
		std::cin >> st[i].score[0];
		std::cout << "score two = ";
		std::cin >> st[i].score[1];
		std::cout << "score three = ";
		std::cin >> st[i].score[2];
		std::cout << "\n";
	}

	for(int i = 0; i < n; i++){

		std::cout << "First Name = " << st[i].firstName << "\n";
		std::cout << "Last Name = "<< st[i].lastName << "\n";
		std::cout << "Score One = "<< st[i].score[0] << "\n";
		std::cout << "Score Two = "<< st[i].score[1] << "\n";
		std::cout << "Score Three = "<< st[i].score[2] << "\n";
		std::cout << "\n";
	}
	
	std::cout << "\n";
	sort(st, n);
	return 0;
}
