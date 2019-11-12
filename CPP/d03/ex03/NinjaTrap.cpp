#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( void ) : ClapTrap() {
	this->_hp = 60;
	this->_maxHp = 60;
	this->_ep = 120;
	this->_maxEp = 120;
	this->_mDmg = 60;
	this->_rDmg = 5;
	this->_dmgReduct = 0;
	std::cout << this->_name << " : ... *silent as expected*" << std::endl;
	return;
}

NinjaTrap::NinjaTrap( NinjaTrap const & src ) : ClapTrap(src) {
	this->_hp = 60;
	this->_maxHp = 60;
	this->_ep = 120;
	this->_maxEp = 120;
	this->_mDmg = 60;
	this->_rDmg = 5;
	this->_dmgReduct = 0;
	*this = src;
	std::cout << this->_name << " : ... *silent as expected*" << std::endl;
	return;
}

NinjaTrap::NinjaTrap( std::string str ) : ClapTrap(str) {
	this->_hp = 60;
	this->_maxHp = 60;
	this->_ep = 120;
	this->_maxEp = 120;
	this->_mDmg = 60;
	this->_rDmg = 5;
	this->_dmgReduct = 0;
	std::cout << this->_name << " : ... *silent as expected*" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap( void ) {
	std::cout << this->_name << " : ... *silent as expected*" << std::endl;
	return;
}

unsigned int	NinjaTrap::meleeAttack( std::string const & target ) const {
	std::cout << this->_name << " : ... *silent as expected*" << std::endl;
	return this->_melee(target);
}

unsigned int	NinjaTrap::rangedAttack( std::string const & target ) const {
	std::cout << this->_name << " : ... *silent as expected*" << std::endl;
	return this->_ranged(target);
}

void			NinjaTrap::ninjaShoebox(FragTrap & target) {
	if (this->_ep >= 20) {
		std::cout << this->_name << " : ... *silent as expected*" << std::endl;
		std::cout << this->_name << " - attacks " << target.getName();
		std::cout << " with shadow powers, causing 35" << " points of damage !";
		std::cout << std::endl;
		target.takeDamage(35);
		this->setEp(this->_ep - 20);
	}
	else {
		std::cout << this->_name << " : ";
		std::cout << " ... *apprently trying something in vain" << std::endl;
	}
	return;
}

void			NinjaTrap::ninjaShoebox(ScavTrap & target) {
	if (this->_ep >= 20) {
		std::cout << this->_name << " : ... *silent as expected*" << std::endl;
		std::cout << this->_name << " - attacks " << target.getName();
		std::cout << " with a unidentified ninja weapon, causing 35";
		std::cout << " points of damage !" << std::endl;
		target.takeDamage(35);
		this->setEp(this->_ep - 20);
	}
	else {
		std::cout << this->_name << " : ";
		std::cout << " ... *apprently trying something in vain" << std::endl;
	}
	return;
}

void			NinjaTrap::ninjaShoebox(NinjaTrap & target) {
	if (this->_ep >= 20) {
		std::cout << this->_name << " : FUCK THIS *wow didnt see that coming*" << std::endl;
		std::cout << this->_name << " - attacks " << target.getName();
		std::cout << " with A FREAKING HEADBUTT OMFG, causing 35";
		std::cout << " points of damage !" << std::endl;
		target.takeDamage(35);
		this->setEp(this->_ep - 20);
	}
	else {
		std::cout << this->_name << " : ";
		std::cout << " ... *apprently trying something in vain" << std::endl;
	}
	return;
}

NinjaTrap &		NinjaTrap::operator=(NinjaTrap const & rhs) {
	ClapTrap::operator=(rhs);
	return *this;
}