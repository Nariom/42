#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) :
	_hp(100),
	_maxHp(100),
	_ep(50),
	_maxEp(50),
	_level(1),
	_name("ClapTrap"),
	_mDmg(20),
	_rDmg(15),
	_dmgReduct(3)
{
	std::cout << this->_name << " : ";
	std::cout << "Does this mean I can start dancing? Pleeeeeeaaaaase?";
	std::cout << std::endl;
	return;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {
	*this = src;
	std::cout << this->_name << " : ";
	std::cout << "Does this mean I can start dancing? Pleeeeeeaaaaase?";
	std::cout << std::endl;
	return;
}

ScavTrap::ScavTrap( std::string str ) :
	_hp(100),
	_maxHp(100),
	_ep(50),
	_maxEp(50),
	_level(1),
	_name(str),
	_mDmg(20),
	_rDmg(15),
	_dmgReduct(3)
{
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

unsigned int	ScavTrap::getHp( void ) const {
	return this->_hp;
}

void			ScavTrap::setHp( unsigned int val ) {
	if (val <= this->_maxHp)
		this->_hp = val;
	else
		this->_hp = this->_maxHp;
	return;
}

unsigned int	ScavTrap::getMaxHp( void ) const {
	return this->_maxHp;
}

void			ScavTrap::setMaxHp( unsigned int val ) {
	this->_maxHp = val;
	if (this->_hp > val)
		this->_hp = val;
	return;
}

unsigned int	ScavTrap::getEp( void ) const {
	return this->_ep;
}

void			ScavTrap::setEp( unsigned int val ) {
	if (val <= this->_maxEp)
		this->_ep = val;
	else
		this->_ep = this->_maxEp;
	return;
}

unsigned int	ScavTrap::getMaxEp( void ) const {
	return this->_maxEp;
}

void			ScavTrap::setMaxEp( unsigned int val ) {
	this->_maxEp = val;
	if (this->_ep > val)
		this->_ep = val;
	return;
}

unsigned int	ScavTrap::getLevel( void ) const {
	return this->_level;
}

void			ScavTrap::setLevel( unsigned int val ) {
	this->_level = val;
	return;
}

std::string		ScavTrap::getName( void ) const {
	return this->_name;
}

void			ScavTrap::setName( std::string val ) {
	this->_name = val;
	return;
}

unsigned int	ScavTrap::getMDmg( void ) const {
	return this->_mDmg;
}

void			ScavTrap::setMDmg( unsigned int val ) {
	this->_mDmg = val;
	return;
}

unsigned int	ScavTrap::getRDmg( void ) const {
	return this->_rDmg;
}

void			ScavTrap::setRDmg( unsigned int val ) {
	this->_rDmg = val;
	return;
}

unsigned int	ScavTrap::getDmgReduct( void ) const {
	return this->_dmgReduct;
}

void			ScavTrap::setDmgReduct( unsigned int val ) {
	this->_dmgReduct = val;
	return;
}

void			ScavTrap::takeDamage( unsigned int amount ) {
	amount = (amount > this->_dmgReduct) ? amount - this->_dmgReduct : 0;
	amount = (amount > this->_hp) ? this->_hp : amount;
	if (amount > 0) {
		std::cout << this->_name << " : ";
		std::cout << "I bet your mom could do better" << std::endl;
		this->setHp(this->_hp - amount);
	}
	return;
}

void			ScavTrap::beRepaired( unsigned int amount ) {
	std::cout << this->_name << " : ";
	std::cout << "Wow, that actually worked?" << std::endl;
	std::cout << "SC4V-TP " << this->_name << " repair for ";
	std::cout << amount << " HP !" << std::endl;
	this->setHp(this->_hp + amount);
	return;
}

unsigned int	ScavTrap::meleeAttack( std::string const & target ) const {
	std::cout << this->_name << " : " << "Take That" << std::endl;
	std::cout << "SC4V-TP " << this->_name << " attacks " << target;
	std::cout << " at melee, causing " << this->_mDmg << " points of damage !";
	std::cout << std::endl;
	return this->_mDmg;
}

unsigned int	ScavTrap::rangedAttack( std::string const & target ) const {
	std::cout << this->_name << " : ";
	std::cout << "In yo' FACE!" << std::endl;
	std::cout << "SC4V-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_mDmg << " points of damage !";
	std::cout << std::endl;
	return this->_rDmg;
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
	this->_hp = rhs.getHp();
	this->_maxHp = rhs.getMaxHp();
	this->_ep = rhs.getEp();
	this->_maxEp = rhs.getMaxEp();
	this->_level = rhs.getLevel();
	this->_name = rhs.getName();
	this->_mDmg = rhs.getMDmg();
	this->_rDmg = rhs.getRDmg();
	this->_dmgReduct = rhs.getDmgReduct();
	return *this;
}