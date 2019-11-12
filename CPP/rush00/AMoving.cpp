// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMoving.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:45:54 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:21:03 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AMoving.hpp"

AMoving::AMoving() : _x(0), _y(0), _symbol('.'), _speed(1), _time((double) clock() / (double) CLOCKS_PER_SEC)
{
}

AMoving::AMoving(int x, int y, char symbol, int speed, int direction) : _x(x), _y(y), _symbol(symbol), _speed(speed), _direction(direction), _time((double) clock() / (double) CLOCKS_PER_SEC)
{
}

AMoving::AMoving(AMoving const & src)
{
    *this = src;
}

AMoving::~AMoving()
{
}

int AMoving::getX(void) const
{
    return this->_x;
}

int AMoving::getY(void) const
{
    return this->_y;
}

char AMoving::getSymbol(void) const
{
    return this->_symbol;
}

int AMoving::getSpeed(void) const
{
    return this->_speed;
}

int AMoving::getDirection(void) const
{
    return this->_direction;
}

void AMoving::moveX(int x)
{
    this->_x = x;
}

void AMoving::moveY(int y)
{
    this->_y = y;
}

double AMoving::getTime(void) const {
    return this->_time;
}

void AMoving::setTime(double newTime) {
    this->_time = newTime;
}

AMoving & AMoving::operator=(AMoving const & other)
{
    this->_x = other._x;
    this->_y = other._y;
    this->_symbol = other._symbol;
    this->_speed = other._speed;
	this->_direction = other._direction;
    return *this;
}
