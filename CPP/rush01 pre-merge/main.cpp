#include <iostream>
#include <ncurses.h>
#include "NCurseDisplay.hpp"
#include "Module.hpp"

int	main(void) {

	NCurseDisplay	curse;
	char			ch;
	Module *		tmp;

	try {
		curse.init_disp();
	}
	catch (NCurseDisplay::TooShort & e) {
		std::cout << e.what() << std::endl;
		return -1;
	}

	for(int i = 0; i < 10; ++i) {
		tmp = new Module("temp");
		try {
			curse.add_mod(*tmp);
		}
		catch (NCurseDisplay::TooShort & e) {
			std::cout << e.what() << std::endl;
			return -1;
		}
	}

	while (true) {
		curse.refresh();
		switch (ch = getch()) {
			case 27:
				curse.restore();
				return 0;
			default:
				break;
		}
	}

}