#include "Institution.h"

int main(){
	Institution in("Yaroslav Svidunovich", 20);
	in.output();

	School a2(5, 21, 3);
	a2.out();
   	a2.input("Yaroslav Svidun", 11);	
	a2.output();
	a2.averageTeacherSchool();

	College b2(7, 88, 4);
	b2.out();
	b2.input("Alex Hill" , 49);
	b2.output();	
	b2.averageTeacherCollege();

	University c2(24, 614, 5);
	c2.out();
	c2.input("Jonn Bear", 22);
	c2.output();
	c2.averageTeacherUniversity();
	return 0;
}
