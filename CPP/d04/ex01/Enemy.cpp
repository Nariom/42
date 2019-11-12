#include "Enemy.hpp"

Enemy::Enemy( void ) { return; }

Enemy::Enemy( Enemy const & src ) {
	*this = src;
	return;
}

Enemy::Enemy(int hp, std::string const & type) :
	_hp(hp),
	_type(type)
{ return; }

Enemy::~Enemy( void ) { return; }

std::string const	Enemy::getType() const { return this->_type; }
int					Enemy::getHP() const { return this->_hp; }

void				Enemy::takeDamage(int dmg) {
	if (dmg)
		this->_hp -= dmg;
}

Enemy &				Enemy::operator=(Enemy const & rhs) {
	this->_type = rhs.getType();
	this->_hp = rhs.getHP();
	return *this;
}