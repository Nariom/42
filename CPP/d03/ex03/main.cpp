#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int	main( void ) {

	FragTrap	*robotOne = new FragTrap("Cluck-Trap");
	ScavTrap	*robotTwo = new ScavTrap("MINAC");
	NinjaTrap	*robotThree = new NinjaTrap("Shadow");

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
		robotThree->ninjaShoebox(*robotOne);
		if (robotOne->getHp() == 0) {
			delete robotOne;
			robotOne = 0;
		}
	}

	while (robotOne || robotTwo) {
		if (robotOne) {
			robotThree->ninjaShoebox(*robotOne);
			if (robotOne->getHp() == 0) {
				delete robotOne;
				robotOne = 0;
			}
		}
		if (robotTwo) {
			robotThree->ninjaShoebox(*robotTwo);
			if (robotTwo->getHp() == 0) {
				delete robotTwo;
				robotTwo = 0;
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

	if (robotThree) {
		delete robotThree;
		robotThree = 0;
	}
}