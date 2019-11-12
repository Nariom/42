// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Grunt.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:33:29 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:45:06 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Grunt.hpp"

Grunt::Grunt() : AEnemy()
{
}

Grunt::Grunt(int x, int y, char symbol, int speed, int direction, int hp, int size, int points) : AEnemy(x, y, symbol, speed, direction, hp, size, points)
{
}

Grunt::Grunt(Grunt const & src) : AEnemy(src)
{
}

Grunt::~Grunt()
{
}

void Grunt::move(void)
{
	std::cout << "grunt moves" << std::endl;
}

Missile* Grunt::shoot(void)
{
	Missile* fire = new Missile(this->_x - 2, this->_y, '=', 20, -1);
	return fire;
}

Grunt & Grunt::operator=(Grunt const & other)
{
	AEnemy::operator=(other);
    return *this;
}
