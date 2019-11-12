#ifndef FAKEMODULE_HPP
# define FAKEMODULE_HPP
# include <string>
# include <list>
# include "IMonitorModule.hpp"
# include "IMonitorDisplay.hpp"
# include "AOutput.hpp"

class Module : public IMonitorModule {

	typedef std::list<AOutput>	olist;

private:

	std::string	_name;
	olist		_outputs;

	Module( void );
	Module( Module const & src );

	Module &	operator=(Module const & rhs);

public:

	Module( std::string	name );
	~Module( void );

	virtual int		nbLines( void );
	virtual void	get_displayed( IMonitorDisplay & disp );
	virtual void	disp_title( IMonitorDisplay & disp );

};

#endif