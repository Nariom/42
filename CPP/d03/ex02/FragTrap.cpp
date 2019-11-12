#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	this->_ep = 100;
	this->_maxEp = 100;
	this->_mDmg = 30;
	this->_rDmg = 20;
	this->_dmgReduct = 5;
	std::cout << this->_name << " : ";
	std::cout << "Directive one: Protect humanity! ";
	std::cout << "Directive two: Obey Jack at all costs. ";
	std::cout << "Directive three: Dance!" << std::endl;
	return;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap(src) {
	this->_ep = 100;
	this->_maxEp = 100;
	this->_mDmg = 30;
	this->_rDmg = 20;
	this->_dmgReduct = 5;
	*this = src;
	std::cout << this->_name << " : ";
	std::cout << "Directive one: Protect humanity! ";
	std::cout << "Directive two: Obey Jack at all costs. ";
	std::cout << "Directive three: Dance!" << std::endl;
	return;
}

FragTrap::FragTrap( std::string str ) : ClapTrap(str) {
	this->_ep = 100;
	this->_maxEp = 100;
	this->_mDmg = 30;
	this->_rDmg = 20;
	this->_dmgReduct = 5;
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

unsigned int	FragTrap::meleeAttack( std::string const & target ) const {
	std::cout << this->_name << " : " << "Bop!" << std::endl;
	return this->_melee(target);
}

unsigned int	FragTrap::rangedAttack( std::string const & target ) const {
	std::cout << this->_name << " : ";
	std::cout << "I am a tornado of death and bullets!" << std::endl;
	return this->_ranged(target);
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
	ClapTrap::operator=(rhs);
	return *this;
}