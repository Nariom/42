// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:10:30 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:54:00 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"

Player::Player() : AShip()
{
}

Player::Player(int x, int y, char symbol, int speed, int direction, int hp, int size) : AShip(x, y, symbol, speed, direction, hp, size)
{
}

Player::Player(Player const & src) : AShip(src)
{
}

Player::~Player()
{
}

Missile* Player::shoot(void)
{
	Missile* fire = new Missile(this->_x + 2, this->_y, '-', 20, 1);

	return fire;
}

Player & Player::operator=(Player const & other)
{
	AShip::operator=(other);
    return *this;
}
