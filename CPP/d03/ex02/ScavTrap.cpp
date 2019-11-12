#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->_ep = 50;
	this->_maxEp = 50;
	this->_mDmg = 20;
	this->_rDmg = 15;
	this->_dmgReduct = 3;
	std::cout << this->_name << " : ";
	std::cout << "Does this mean I can start dancing? Pleeeeeeaaaaase?";
	std::cout << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src) {
	this->_ep = 50;
	this->_maxEp = 50;
	this->_mDmg = 20;
	this->_rDmg = 15;
	this->_dmgReduct = 3;
	*this = src;
	std::cout << this->_name << " : ";
	std::cout << "Does this mean I can start dancing? Pleeeeeeaaaaase?";
	std::cout << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string str ) : ClapTrap(str) {
	this->_ep = 50;
	this->_maxEp = 50;
	this->_mDmg = 20;
	this->_rDmg = 15;
	this->_dmgReduct = 3;
	std::cout << this->_name << " : ";
	std::cout << "Does this mean I can start dancing? Pleeeeeeaaaaase?";
	std::cout << std::endl;
	return;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << this->_name << " : ";
	std::cout << "Good! I didnt want to be scrap metal anyway!" << std::endl;
	return;
}

unsigned int	ScavTrap::meleeAttack( std::string const & target ) const {
	std::cout << this->_name << " : ";
	std::cout << "Wow, that actually worked?" << std::endl;
	return this->_melee(target);
}

unsigned int	ScavTrap::rangedAttack( std::string const & target ) const {
	std::cout << this->_name << " : " << "Take That" << std::endl;
	return this->_ranged(target);
}

void			ScavTrap::challengeNewcomer( std::string const & target ) const {
	std::string		challenges[5] = {
		"Do a barrel roll, bitch !",
		"EAT YO OWN FEET",
		"Try to one shot me, but not in the face please.",
		"Uh ... I dunno man ... maybe you can ... make me a sandwich ?",
		"Alright, I'm done here. Do whatever you want."
	};
	int				nb = rand() % 5;
	std::cout << this->_name << " : " << target << " ! ";
	std::cout << "I have a challenge for ya ! " << challenges[nb];
	std::cout << std::endl;
	return;
}

ScavTrap &		ScavTrap::operator=(ScavTrap const & rhs) {
	ClapTrap::operator=(rhs);
	return *this;
}