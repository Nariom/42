// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Missile.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:56:15 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:40:20 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Missile.hpp"

Missile::Missile() : AMoving()
{
}

Missile::Missile(int x, int y, char symbol, int speed, int direction) : AMoving(x, y, symbol, speed, direction)
{
}

Missile::Missile(Missile const & src) : AMoving(src)
{
    *this = src;
}

Missile::~Missile()
{
}

void Missile::move()
{
	std::cout << "flying missile" << std::endl;
}

Missile & Missile::operator=(Missile const & other)
{
	AMoving::operator=(other);
    return *this;
}
