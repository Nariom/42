#ifndef NCURSEDISPLAY_HPP
# define NCURSEDISPLAY_HPP
# include <ncurses.h>
# include <ctime>
# include <sstream>
# include <list>
# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"

class NCurseDisplay : public IMonitorDisplay {

	typedef std::pair<IMonitorModule &, WINDOW * >	pair;
	typedef std::list< pair >						pair_list;

private:

	static const int	modWidth;
	static const int	offset;

	int			_height;
	int			_width;
	double		_time;
	pair_list	_modules;
	int *		_occupied;
	WINDOW *	_current;

	NCurseDisplay( NCurseDisplay const & src );

	NCurseDisplay &	operator=(NCurseDisplay const & rhs);

	virtual void	_disp_all( void );

public:

	NCurseDisplay( void );
	~NCurseDisplay( void );

	virtual void	init_disp( void );
	virtual void	add_mod( IMonitorModule & mod );
	virtual void	refresh( void );
	virtual void	disp_string( std::string str );
	virtual void	disp_string_center( std::string str );
	virtual void	disp_val( int val );
	virtual void	disp_percent( int val1, int val2 );
	virtual void	restore( void );

	class TooShort : public std::exception {
	public:
		TooShort( void );
		TooShort( TooShort const & src );
		~TooShort( void ) throw();
		TooShort &	operator=(TooShort const & rhs);
		virtual const char*	what() const throw();
	};

};

#endif