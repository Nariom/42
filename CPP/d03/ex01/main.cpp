#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main( void ) {

	FragTrap	*robotOne = new FragTrap("Cluck-Trap");
	ScavTrap	*robotTwo = new ScavTrap("MINAC");

	robotTwo->takeDamage(robotOne->meleeAttack(robotTwo->getName()));

	robotOne->takeDamage(robotTwo->rangedAttack(robotOne->getName()));

	robotOne->beRepaired(10);
	robotTwo->beRepaired(10);

	while (robotOne && robotTwo && robotOne->getEp()) {
		robotTwo->challengeNewcomer(robotOne->getName());
		robotTwo->takeDamage(robotOne->vaulthunter_dot_exe(robotTwo->getName()));
		if (robotTwo->getHp() == 0) {
			delete robotTwo;
			robotTwo = 0;
		}
	}

	if (robotOne && robotTwo)
		robotTwo->takeDamage(robotOne->vaulthunter_dot_exe(robotTwo->getName()));

	while (robotOne && robotTwo) {
		robotTwo->takeDamage(robotOne->meleeAttack(robotTwo->getName()));
		if (robotTwo->getHp() == 0) {
			delete robotTwo;
			robotTwo = 0;
		}
		else {
			robotOne->takeDamage(robotTwo->rangedAttack(robotOne->getName()));
			if (robotOne->getHp() == 0) {
				delete robotOne;
				robotOne = 0;
			}
		}
	}

	std::cout << ">>> Deleting remaining robot for the end of the program <<<" << std::endl;

	if (robotOne) {
		delete robotOne;
		robotTwo = 0;
	}

	if (robotTwo) {
		delete robotTwo;
		robotTwo = 0;
	}
}