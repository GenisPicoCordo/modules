#include "Zombie.hpp"

int main(){
	
	Zombie myZombie("PACO");
	Zombie myZombie2("PACO2");
	myZombie.announce();
	myZombie2.announce();
	
	Zombie* noemi = newZombie("Noemi");
	noemi->announce();
	delete noemi;
	randomChump("Genis");

	return 0;
}