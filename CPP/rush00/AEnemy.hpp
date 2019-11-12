// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEnemy.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:18:03 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:49:57 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AENEMY_H
# define AENEMY_H

# include <iostream>
# include <string>

# include "AShip.hpp"

class AEnemy : public AShip
{
private:
    int _points;

public:
    AEnemy(void);
	AEnemy(int x, int y, char symbol, int speed, int direction, int hp, int size, int points);
    AEnemy(AEnemy const & src);
    ~AEnemy(void);

    int getPoints(void) const;

	virtual void move(void) = 0;
	virtual Missile* shoot(void) = 0;

    AEnemy & operator=(AEnemy const & other);
};

#endif
