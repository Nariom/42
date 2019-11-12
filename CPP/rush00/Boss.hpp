// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Boss.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:26:04 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:43:55 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BOSS_H
# define BOSS_H

# include <iostream>
# include <string>

# include "AEnemy.hpp"
# include "Missile.hpp"

class Boss : public AEnemy
{
private:

public:
    Boss(void);
	Boss(int x, int y, char symbol, int speed, int direction, int hp, int size, int points);
    Boss(Boss const & src);
    ~Boss(void);

	void move(void);
	Missile* shoot(void);

    Boss & operator=(Boss const & other);
};


#endif
