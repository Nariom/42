// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMoving.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 12:45:29 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:20:13 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMOVING_H
# define AMOVING_H

# include <iostream>
# include <string>
# include <ctime>

class AMoving
{
protected:
    int _x;
    int _y;
    char _symbol;
    int _speed;
	int _direction;
    double _time;

public:
    AMoving(void);
	AMoving(int x, int y, char symbol, int speed, int direction);
    AMoving(AMoving const & src);
    virtual ~AMoving(void);

    int getX(void) const;
    int getY(void) const;
    char getSymbol(void) const;
    int getSpeed(void) const;
	int getDirection(void) const;
    double getTime(void) const;
    void setTime(double newTime);

    void moveX(int x);
    void moveY(int y);

    AMoving & operator=(AMoving const & other);
};

#endif
