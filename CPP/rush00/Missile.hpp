// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Missile.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:55:51 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:47:17 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MISSILE_H
# define MISSILE_H

# include <iostream>
# include <string>

# include "AMoving.hpp"

class Missile : public AMoving
{
private:

public:
    Missile(void);
	Missile(int x, int y, char symbol, int speed, int direction);
    Missile(Missile const & src);
    ~Missile(void);

	void move();

    Missile & operator=(Missile const & other);
};

#endif
