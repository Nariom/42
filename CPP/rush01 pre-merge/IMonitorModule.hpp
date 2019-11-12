#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP
# include "IMonitorDisplay.hpp"

class IMonitorDisplay;

class IMonitorModule {

public:

	virtual int		nbLines( void ) = 0;
	virtual void	get_displayed( IMonitorDisplay & disp ) = 0;
	virtual void	disp_title( IMonitorDisplay & disp ) = 0;

};

#endif