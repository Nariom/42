#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP
# include <curses.h>
# include <ctime>
# include <cstdlib>
# include <sstream>
# include "AMoving.hpp"
# include "Player.hpp"
# include "Missile.hpp"
# include "Grunt.hpp"

class Game {

private:

	int			_xOff;
	int			_yOff;
	int			_maxH;
	int			_maxW;
	int			_height;
	int			_width;
	int			_hH;
	int			_hW;
	int			_fH;
	int			_fW;
	WINDOW *	_win;
	WINDOW *	_header;
	WINDOW *	_footer;
	Player *	_player;
	AMoving ***	_board;
	double		_time;
	bool		_first;
	int			_lives;
	bool		_isDead;
	int			_score;

	Game( void );
	Game( Game const & src );

	Game &		operator=( Game const & rhs );

	void		_makeFooter( int ticks ) const;
	void		_addEnemies( void );
	void		_moveObjects( double secs );
	void		_renderAll( void ) const;
	void		_horizontalMove( AMoving * mover );
	void		_verticalMove( AMoving * mover );
	void		_horizontalMove( Player * mover, int direction );
	void		_verticalMove( Player * mover, int direction );
	void		_collision( AMoving * mover, int x, int y);
	void		_collision( int x, int y);
	void		_dead(void);
	void		_gameOver(void);

public:

	Game( int x, int y );
	~Game( void );

	bool		refresh( void );
	void		moveUp( void );
	void		moveDown( void );
	void		moveLeft( void );
	void		moveRight( void );
	void		shoot( void );
	void		affScore( void ) const;

};

#endif // GAME_CLASS_HPP