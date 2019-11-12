// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AShip.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:50:48 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:52:56 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AShip.hpp"

AShip::AShip() : AMoving(), _hp(1), _size(1)
{
}

AShip::AShip(int x, int y, char symbol, int speed, int direction, int hp, int size) : AMoving(x, y, symbol, speed, direction), _hp(hp), _size(size)
{
}

AShip::AShip(AShip const & src) : AMoving(src), _hp(src._hp), _size(src._size)
{
}

AShip::~AShip()
{
}

int AShip::getHp(void) const
{
    return this->_hp;
}

int AShip::getSize(void) const
{
    return this->_size;
}

void AShip::move()
{
	std::cout << "ship moving" << std::endl;
}

Missile* shoot(void) // ??
{
	std::cout << "ship firing" << std::endl;
	return 0;
}

AShip & AShip::operator=(AShip const & other)
{
	AMoving::operator=(other);
	this->_hp = other._hp;
	this->_size = other._size;
    return *this;
}
