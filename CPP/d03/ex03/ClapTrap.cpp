#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) :
	_hp(100),
	_maxHp(100),
	_level(1),
	_name("ClapTrap")
{
	std::cout << "ClapTrap " << this->_name << " - constructed.";
	std::cout << std::endl;
	return;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {
	*this = src;
	std::cout << "ClapTrap " << this->_name << " - constructed.";
	std::cout << std::endl;
	return;
}

ClapTrap::ClapTrap( std::string str ) :
	_hp(100),
	_maxHp(100),
	_level(1),
	_name(str)
{
	std::cout << "ClapTrap " << this->_name << " - constructed.";
	std::cout << std::endl;
	return;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << this->_name << " - destructed.";
	std::cout << std::endl;
	return;
}

unsigned int	ClapTrap::getHp( void ) const {
	return this->_hp;
}

void			ClapTrap::setHp( unsigned int val ) {
	if (val <= this->_maxHp)
		this->_hp = val;
	else
		this->_hp = this->_maxHp;
	return;
}

unsigned int	ClapTrap::getMaxHp( void ) const {
	return this->_maxHp;
}

void			ClapTrap::setMaxHp( unsigned int val ) {
	this->_maxHp = val;
	if (this->_hp > val)
		this->_hp = val;
	return;
}

unsigned int	ClapTrap::getEp( void ) const {
	return this->_ep;
}

void			ClapTrap::setEp( unsigned int val ) {
	if (val <= this->_maxEp)
		this->_ep = val;
	else
		this->_ep = this->_maxEp;
	return;
}

unsigned int	ClapTrap::getMaxEp( void ) const {
	return this->_maxEp;
}

void			ClapTrap::setMaxEp( unsigned int val ) {
	this->_maxEp = val;
	if (this->_ep > val)
		this->_ep = val;
	return;
}

unsigned int	ClapTrap::getLevel( void ) const {
	return this->_level;
}

void			ClapTrap::setLevel( unsigned int val ) {
	this->_level = val;
	return;
}

std::string		ClapTrap::getName( void ) const {
	return this->_name;
}

void			ClapTrap::setName( std::string val ) {
	this->_name = val;
	return;
}

unsigned int	ClapTrap::getMDmg( void ) const {
	return this->_mDmg;
}

void			ClapTrap::setMDmg( unsigned int val ) {
	this->_mDmg = val;
	return;
}

unsigned int	ClapTrap::getRDmg( void ) const {
	return this->_rDmg;
}

void			ClapTrap::setRDmg( unsigned int val ) {
	this->_rDmg = val;
	return;
}

unsigned int	ClapTrap::getDmgReduct( void ) const {
	return this->_dmgReduct;
}

void			ClapTrap::setDmgReduct( unsigned int val ) {
	this->_dmgReduct = val;
	return;
}

void			ClapTrap::takeDamage( unsigned int amount ) {
	std::cout << this->_name;
	amount = (amount > this->_dmgReduct) ? amount - this->_dmgReduct : 0;
	amount = (amount > this->_hp) ? this->_hp : amount;
	if (amount > 0) {
		std::cout << " - took " << amount << " damage(s).";
		this->setHp(this->_hp - amount);
	}
	else
		std::cout << " - was hit but armor took it all.";
	std::cout << std::endl;
	return;
}

void			ClapTrap::beRepaired( unsigned int amount ) {
	std::cout << this->_name;
	amount = (amount + this->_hp > this->_maxHp) ? this->_maxHp - this->_hp : amount;
	if (amount > 0) {
		std::cout << " - repair for " << amount << " hp.";
		this->setHp(this->_hp + amount);
	}
	else
		std::cout << " - try to repair but is full health.";
	std::cout << std::endl;
	return;
}

unsigned int	ClapTrap::_melee( std::string const & target ) const {
	std::cout << this->_name << " - attacks ";
	std::cout << target << " at melee, causing " << this->_mDmg;
	std::cout << " points of damage !" << std::endl;
	return this->_mDmg;
}

unsigned int	ClapTrap::_ranged( std::string const & target ) const {
	std::cout << this->_name << " - attacks ";
	std::cout << target << " at range, causing " << this->_rDmg;
	std::cout << " points of damage !" << std::endl;
	return this->_rDmg;
}

ClapTrap &		ClapTrap::operator=(ClapTrap const & rhs) {
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