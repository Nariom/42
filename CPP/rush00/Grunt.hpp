// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Grunt.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:32:29 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:44:33 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GRUNT_H
# define GRUNT_H

# include <iostream>
# include <string>

# include "AEnemy.hpp"
# include "Missile.hpp"

class Grunt : public AEnemy
{
private:

public:
    Grunt(void);
	Grunt(int x, int y, char symbol, int speed, int direction, int hp, int size, int points);
    Grunt(Grunt const & src);
    ~Grunt(void);

	void move(void);
	Missile* shoot(void);

    Grunt & operator=(Grunt const & other);
};


#endif
