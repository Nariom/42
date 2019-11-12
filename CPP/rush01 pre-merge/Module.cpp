#include "Module.hpp"

Module::Module( std::string	name ) : _name(name) {}

Module::~Module( void ) {}

int		Module::nbLines( void ) { return /*this->_outputs.size()*/10; }

void	Module::get_displayed( IMonitorDisplay & disp ) {

	olist::iterator	it, ite;

	ite = this->_modules.end();
	for (it = this->_modules.begin(); it != ite; ++it)
		it->get_displayed(disp);
	(void) disp;

}

void	Module::disp_title( IMonitorDisplay & disp ) {
	disp.disp_string_center(this->_name);
}