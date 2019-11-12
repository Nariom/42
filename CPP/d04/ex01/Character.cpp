#include "Character.hpp"

Character::Character( void ) : _name("Character") { return; }

Character::Character( Character const & src ) {
	*this = src;
	return;
}

Character::Character( std::string const & name ) :
	_name(name),
	_ap(40),
	_weapon(0)
{ return; }

Character::~Character( void ) { return; }


std::string const	Character::getName() const { return this->_name; }

int					Character::getAp() const { return this->_ap; }

AWeapon *			Character::getWeapon() const { return this->_weapon; }

void				Character::recoverAP() {
	this->_ap = (this->_ap < 30) ? this->_ap + 10 : 40;
	std::cout << "10 AP recovered !" << std::endl;
}

void				Character::equip( AWeapon* weapon ) {
	this->_weapon = weapon;
}

void				Character::attack( Enemy* enemy ) {
	if (this->_weapon and this->_weapon->getAPCost() <= this->_ap) {
		std::cout << this->_name << " attacks " << enemy->getType();
		std::cout << " with a " << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0)
			delete enemy;
		this->_ap -= this->_weapon->getAPCost();
	}
	else
		std::cout << "Not enough AP." << std::endl;
}

Character &			Character::operator=(Character const & rhs) {
	this->_name = rhs.getName();
	this->_ap = rhs.getAp();
	this->_weapon = rhs.getWeapon();
	return *this;
}

std::ostream &		operator<<( std::ostream & o, Character const & rhs ) {
	o << rhs.getName() << " has " << rhs.getAp() << " AP and ";
	if (rhs.getWeapon())
		o << "wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		o << "is unarmed" << std::endl;
	return o;
}