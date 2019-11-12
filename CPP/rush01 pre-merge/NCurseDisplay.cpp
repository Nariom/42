#include "NCurseDisplay.hpp"

const int	NCurseDisplay::modWidth = 50;
const int	NCurseDisplay::offset = 4;

NCurseDisplay::NCurseDisplay( void ) {}

NCurseDisplay::~NCurseDisplay( void ) {

	pair_list::iterator	it, ite;

	ite = this->_modules.end();
	for (it = this->_modules.begin(); it != ite; ++it)
		delwin(it->second);

	if (this->_occupied)
		delete [] this->_occupied;

}

void	NCurseDisplay::init_disp( void ) {

	int	size = NCurseDisplay::modWidth + NCurseDisplay::offset + 1;

	initscr();
	getmaxyx(stdscr, this->_height, this->_width);
	if (this->_width < size) {
		endwin();
		this->_occupied = 0;
		throw NCurseDisplay::TooShort();
	}
	else {
		raw();
		noecho();
		nodelay(stdscr, TRUE);
		curs_set(0);
		erase();
		start_color();
		init_pair(1, COLOR_RED, COLOR_WHITE);
		init_pair(2, COLOR_RED, COLOR_BLACK);
		init_pair(3, COLOR_BLACK, COLOR_RED);
		wbkgd(stdscr, COLOR_PAIR(1));
		wrefresh(stdscr);
		this->_occupied = new int[this->_width / size];
		for (int i = 0; i < this->_width / size; ++i)
			this->_occupied[i] = 1;
		this->_time =  static_cast<double>(clock()) / static_cast<double>(CLOCKS_PER_SEC);
	}
}

void	NCurseDisplay::add_mod( IMonitorModule & mod ) {

	int		i = -1;
	int		size = NCurseDisplay::modWidth + NCurseDisplay::offset + 1;
	pair	newPair(mod, 0);

	while (++i < this->_width / size)
		if (this->_occupied[i] <= this->_height - (mod.nbLines() + 4))
			break;
	if (i == this->_width / size) {
		this->restore();
		throw NCurseDisplay::TooShort();
	}
	else {
		newPair.first = mod;
		newPair.second = newwin(mod.nbLines() + 4, size - 1, this->_occupied[i] + 1, i * size + 1);
		this->_occupied[i] += mod.nbLines() + 5;
		this->_modules.push_back(newPair);
	}

}

void	NCurseDisplay::_disp_all( void ) {

	pair_list::iterator	it, ite;

	ite = this->_modules.end();
	for (it = this->_modules.begin(); it != ite; ++it) {
		werase(it->second);
		wbkgd(it->second, COLOR_PAIR(2));
		box(it->second, 0, 0);
		this->_current = it->second;
		wmove(it->second, 2, 2);
		wattron(it->second, COLOR_PAIR(3));
		it->first.disp_title(*this);
		wattron(it->second, COLOR_PAIR(2));
		wmove(it->second, 3, 1);
		it->first.get_displayed(*this);
		wrefresh(it->second);
	}

}

void	NCurseDisplay::refresh( void ) {

	double	secs = static_cast<double>(clock()) / static_cast<double>(CLOCKS_PER_SEC);

	if (secs - this->_time > 1.0 / 24.0) {
		this->_disp_all();
		this->_time = secs;
	}

}

void	NCurseDisplay::disp_string( std::string str ) { 
	waddstr(this->_current, str.c_str());
}

void	NCurseDisplay::disp_string_center( std::string str ) {

	int 		span = (NCurseDisplay::modWidth - str.length()) / 2;
	std::string	spaces(span, ' ');

	waddstr(this->_current, spaces.c_str());
	waddstr(this->_current, str.c_str());
	waddstr(this->_current, spaces.c_str());

}

void	NCurseDisplay::disp_val( int val ) {

	std::stringstream ss;

	ss << val;
	waddstr(this->_current, ss.str().c_str());

}

void	NCurseDisplay::disp_percent( int val1, int val2 ) { (void) val1; (void) val2; }

void	NCurseDisplay::restore( void ) {
	erase();
	curs_set(1);
	endwin();
}

NCurseDisplay::TooShort::TooShort( void ) {}

NCurseDisplay::TooShort::~TooShort( void ) throw() {}

const char*	NCurseDisplay::TooShort::what() const throw()
{ return "The window is too small."; }