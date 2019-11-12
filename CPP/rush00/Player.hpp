// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 13:10:10 by jmaurice          #+#    #+#             //
//   Updated: 2015/01/10 15:53:02 by jmaurice         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_H
# define PLAYER_H

# include <iostream>
# include <string>

# include "AShip.hpp"
# include "Missile.hpp"

class Player : public AShip
{
private:

public:
    Player(void);
	Player(int x, int y, char symbol, int speed, int direction, int hp, int size);
    Player(Player const & src);
    ~Player(void);

	Missile* shoot(void);

    Player & operator=(Player const & other);
};

#endif
