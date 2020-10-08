#include "Carrier.h"

int main(){
	Car mazda(33);
	mazda.setName("Yaroslav Svidunovich");
	mazda.getName();
	std::cout << mazda.getPassengers() << std::endl;
	mazda.setPassengers(34);
	mazda.setCost(50);
	mazda.getSumCost();
	std::cout << mazda.getPassengers() << std::endl;
	Plane boing(33);
	boing.setName("Alexander Starovoitov");
	boing.getName();

	return 0;
}
