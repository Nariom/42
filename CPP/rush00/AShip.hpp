// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AShip.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:45:22 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:50:57 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASHIP_H
# define ASHIP_H

# include <iostream>
# include <string>

# include "AMoving.hpp"
# include "Missile.hpp"

class AShip : public AMoving
{
private:
    int _hp;
    int _size;

public:
    AShip(void);
	AShip(int x, int y, char symbol, int speed, int direction, int hp, int size);
    AShip(AShip const & src);
    virtual ~AShip(void);

    int getHp(void) const;
    int getSize(void) const;

	virtual void move(void);
	virtual Missile* shoot(void) = 0;

    AShip & operator=(AShip const & other);
};


#endif
