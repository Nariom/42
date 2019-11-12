// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Boss.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:25:55 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:42:25 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Boss.hpp"

Boss::Boss() : AEnemy()
{
}

Boss::Boss(int x, int y, char symbol, int speed, int direction, int hp, int size, int points) : AEnemy(x, y, symbol, speed, direction, hp, size, points)
{
}

Boss::Boss(Boss const & src) : AEnemy(src)
{
}

Boss::~Boss()
{
}

void Boss::move()
{
	std::cout << "boss moves" << std::endl;
}

Missile* Boss::shoot()
{
	Missile* fire = new Missile(this->_x - 1, this->_y, 'x', 2, -1);
	std::cout << "boss shoots" << std::endl;
	return fire;
}

Boss & Boss::operator=(Boss const & other)
{
	AEnemy::operator=(other);
    return *this;
}
