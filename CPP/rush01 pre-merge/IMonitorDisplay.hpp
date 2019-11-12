#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP
# include <string>
# include "IMonitorModule.hpp"

class IMonitorModule;

class IMonitorDisplay {

protected:

	virtual void	_disp_all( void ) = 0;

public:
	
	virtual void	init_disp( void ) = 0;
	virtual void	add_mod( IMonitorModule & mod ) = 0;
	virtual void	refresh( void ) = 0;
	virtual void	disp_string( std::string str ) = 0;
	virtual void	disp_string_center( std::string str ) = 0;
	virtual void	disp_val( int val ) = 0;
	virtual void	disp_percent( int val1, int val2 ) = 0;
	virtual void	restore( void ) = 0;

};

#endif