#include <curses.h>
#include <iostream>
#include <ctime>
#include "Game.class.hpp"

void	restore( void ) {

	curs_set(1);
	endwin();
	
}

int	init( int xOff, int yOff ) {

	int 		h, w;

	initscr();
	getmaxyx(stdscr, h, w);
	if (h < 2 * yOff + 6 || w < 2 * xOff + 6) {
		endwin();
		std::cout << "Window too small." << std::endl;
		return -1;
	}
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	erase();
	wrefresh(stdscr);

	return 1;

}

int	main ( void ) {
	
	int			ch = 0;
	int			xOff = 6;
	int			yOff = 6;

	if (init(xOff, yOff) == -1)
		return -1;

	Game		game(xOff, yOff);

	while (game.refresh()) {
		switch (ch = getch()) {
			case 'w':
				game.moveUp();
				break;
			case 'a':
				game.moveLeft();
				break;
			case 's':
				game.moveDown();
				break;
			case 'd':
				game.moveRight();
				break;
			case ' ':
				game.shoot();
				break;
			case 27:
				restore();
				return 1;
			default:
				break;
		}
	}
	game.affScore();
	while (true) {
		switch (ch = getch()) {
			case 27:
				restore();
				return 1;
			default:
				break;
		}
	}
	restore();
	return 1;

}