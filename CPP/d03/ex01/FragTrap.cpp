#include "FragTrap.hpp"

FragTrap::FragTrap( void ) :
	_hp(100),
	_maxHp(100),
	_ep(100),
	_maxEp(100),
	_level(1),
	_name("ClapTrap"),
	_mDmg(30),
	_rDmg(20),
	_dmgReduct(5)
{
	std::cout << this->_name << " : ";
	std::cout << "Directive one: Protect humanity! ";
	std::cout << "Directive two: Obey Jack at all costs. ";
	std::cout << "Directive three: Dance!" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const & src ) {
	*this = src;
	std::cout << this->_name << " : ";
	std::cout << "Directive one: Protect humanity! ";
	std::cout << "Directive two: Obey Jack at all costs. ";
	std::cout << "Directive three: Dance!" << std::endl;
	return;
}

FragTrap::FragTrap( std::string str ) :
	_hp(100),
	_maxHp(100),
	_ep(100),
	_maxEp(100),
	_level(1),
	_name(str),
	_mDmg(30),
	_rDmg(20),
	_dmgReduct(5)
{
	std::cout << this->_name << " : ";
	std::cout << "Directive one: Protect humanity! ";
	std::cout << "Directive two: Obey Jack at all costs. ";
	std::cout << "Directive three: Dance!" << std::endl;
	return;
}

FragTrap::~FragTrap( void ) {
	std::cout << this->_name << " : ";
	std::cout << "I'll die as I lived: annoying!" << std::endl;
	return;
}

unsigned int	FragTrap::getHp( void ) const {
	return this->_hp;
}

void			FragTrap::setHp( unsigned int val ) {
	if (val <= this->_maxHp)
		this->_hp = val;
	else
		this->_hp = this->_maxHp;
	return;
}

unsigned int	FragTrap::getMaxHp( void ) const {
	return this->_maxHp;
}

void			FragTrap::setMaxHp( unsigned int val ) {
	this->_maxHp = val;
	if (this->_hp > val)
		this->_hp = val;
	return;
}

unsigned int	FragTrap::getEp( void ) const {
	return this->_ep;
}

void			FragTrap::setEp( unsigned int val ) {
	if (val <= this->_maxEp)
		this->_ep = val;
	else
		this->_ep = this->_maxEp;
	return;
}

unsigned int	FragTrap::getMaxEp( void ) const {
	return this->_maxEp;
}

void			FragTrap::setMaxEp( unsigned int val ) {
	this->_maxEp = val;
	if (this->_ep > val)
		this->_ep = val;
	return;
}

unsigned int	FragTrap::getLevel( void ) const {
	return this->_level;
}

void			FragTrap::setLevel( unsigned int val ) {
	this->_level = val;
	return;
}

std::string		FragTrap::getName( void ) const {
	return this->_name;
}

void			FragTrap::setName( std::string val ) {
	this->_name = val;
	return;
}

unsigned int	FragTrap::getMDmg( void ) const {
	return this->_mDmg;
}

void			FragTrap::setMDmg( unsigned int val ) {
	this->_mDmg = val;
	return;
}

unsigned int	FragTrap::getRDmg( void ) const {
	return this->_rDmg;
}

void			FragTrap::setRDmg( unsigned int val ) {
	this->_rDmg = val;
	return;
}

unsigned int	FragTrap::getDmgReduct( void ) const {
	return this->_dmgReduct;
}

void			FragTrap::setDmgReduct( unsigned int val ) {
	this->_dmgReduct = val;
	return;
}

void			FragTrap::takeDamage( unsigned int amount ) {
	amount = (amount > this->_dmgReduct) ? amount - this->_dmgReduct : 0;
	amount = (amount > this->_hp) ? this->_hp : amount;
	if (amount > 0) {
		std::cout << this->_name << " : ";
		std::cout << "I'll stop talking when I'm dead!" << std::endl;
		this->setHp(this->_hp - amount);
	}
	return;
}

void			FragTrap::beRepaired( unsigned int amount ) {
	std::cout << this->_name << " : ";
	std::cout << "Health! Ooh, what flavor is red?" << std::endl;
	std::cout << "FR4G-TP " << this->_name << " repair for ";
	std::cout << amount << " HP !" << std::endl;
	this->setHp(this->_hp + amount);
	return;
}

unsigned int	FragTrap::meleeAttack( std::string const & target ) const {
	std::cout << this->_name << " : " << "Bop!" << std::endl;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target;
	std::cout << " at melee, causing " << this->_mDmg << " points of damage !";
	std::cout << std::endl;
	return this->_mDmg;
}

unsigned int	FragTrap::rangedAttack( std::string const & target ) const {
	std::cout << this->_name << " : ";
	std::cout << "I am a tornado of death and bullets!" << std::endl;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target;
	std::cout << " at range, causing " << this->_mDmg << " points of damage !";
	std::cout << std::endl;
	return this->_rDmg;
}

unsigned int	FragTrap::vaulthunter_dot_exe( std::string const & target ) {
	std::string		attacks[5][2] = {
		 {
		 	"Shhhhhhhh...trap",
		 	"Roses are red/Violets are blue/Wait...how many syllables does that have?"
		 },
		 {
		 	"Miniontrap",
		 	"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew-pew!"
		 },
		 {
		 	"Clap-in-the-Box",
		 	"Some days, you just can't get rid of an obscure pop-culture reference."
		 },
		 {
		 	"One Shot Wonder",
		 	"Like those guys who made only one song ever."
		 },
		 {
		 	"Laser Inferno",
		 	"Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!"
		 }
	};
	unsigned int	dmg[5] = {5, 10, 15, 20, 25};
	if (this->_ep >= 25) {
		int				nb = rand() % 5;
		std::cout << this->_name << " : " << attacks[nb][1] << std::endl;
		std::cout << "FR4G-TP " << this->_name << " attacks " << target;
		std::cout << " with " << attacks[nb][0] << ", causing " << dmg[nb];
		std::cout << " points of damage !" << std::endl;
		this->setEp(this->_ep - 25);
		return dmg[nb];
	}
	else
		std::cout << this->_name << " : " << "Not enough energy :(" << std::endl;
		return 0;
}

FragTrap &		FragTrap::operator=(FragTrap const & rhs) {
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