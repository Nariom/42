#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <string>

class Enemy {

private:

	int					_hp;
	std::string			_type;

	Enemy( void );

public:

	Enemy( Enemy const & src );
	Enemy(int hp, std::string const & type);
	virtual ~Enemy( void );

	Enemy &				operator=(Enemy const & rhs);

	std::string const	getType() const;
	int					getHP() const;

	virtual void		takeDamage(int dmg);

};

#endif // ENEMY_HPP