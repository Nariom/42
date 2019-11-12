#include "Sorcerer.hpp"

Sorcerer::Sorcerer( void ) :
	_name("Sorcerer"),
	_title("Evil")
{ 
	std::cout << "Sorcerer, Evil, is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer( std::string name, std::string title ) :
	_name(name),
	_title(title)
{
	std::cout << name << ", " << title << ", " << "is born !"  << std::endl;
	return;
}

Sorcerer::Sorcerer( Sorcerer const & src ) {
	*this = src;
	std::cout << this->_name << ", " << this->_title << ", " << "is born !";
	std::cout << std::endl;
	return;
}

Sorcerer::~Sorcerer( void ) {
	std::cout << this->_name << ", " << this->_title << ", " << "is dead. ";
	std::cout << "Consequences will never be the same !"  << std::endl;
	return;
}

std::string	Sorcerer::getName( void ) const {
	return this->_name;
}

std::string	Sorcerer::getTitle( void ) const {
	return this->_title;
}

void		Sorcerer::polymorph(Victim const & victim) const {
	victim.getPolymorphed();
	return;
}

Sorcerer &	Sorcerer::operator=(Sorcerer const & rhs) {
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Sorcerer const & rhs ) {
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", ";
	o << "and I like ponies !" << std::endl;
	return o;
}