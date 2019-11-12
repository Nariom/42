// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEnemy.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:18:14 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:48:57 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AEnemy.hpp"

AEnemy::AEnemy() : AShip(), _points(10)
{
}

AEnemy::AEnemy(int x, int y, char symbol, int speed, int direction, int hp, int size, int points) : AShip(x, y, symbol, speed, direction, hp, size), _points(points)
{
}

AEnemy::AEnemy(AEnemy const & src) : AShip(src)
{
}

AEnemy::~AEnemy()
{
}

int AEnemy::getPoints(void) const
{
    return this->_points;
}

AEnemy & AEnemy::operator=(AEnemy const & other)
{
	AShip::operator=(other);
	this->_points = other._points;
    return *this;
}
