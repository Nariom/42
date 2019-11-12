#include "Game.class.hpp"

Game::Game( void ) {}

Game::Game( Game const & src ) {
	*this = src;
	return;
}

Game::Game( int x, int y ) : _xOff(x), _yOff(y) {

	std::string	title =
	" ,---.  ,--. ,--.,------. ,------.,------.      ,---.  ,--.  ,--. ,-----.  ,-----. ,--------.,------.,------.  \n'   .-' |  | |  ||  .--. '|  .---'|  .--. '    '   .-' |  '--'  |'  .-.  ''  .-.  ''--.  .--'|  .---'|  .--. ' \n`.  `-. |  | |  ||  '--' ||  `--, |  '--'.'    `.  `-. |  .--.  ||  | |  ||  | |  |   |  |   |  `--, |  '--'.' \n.-'    |'  '-'  '|  | --' |  `---.|  |\\  \\     .-'    ||  |  |  |'  '-'  ''  '-'  '   |  |   |  `---.|  |\\  \\  \n`-----'  `-----' `--'     `------'`--' '--'    `-----' `--'  `--' `-----'  `-----'    `--'   `------'`--' '--' ";

	//time
	this->_time = (double) clock() / (double) CLOCKS_PER_SEC;
	this->_first = true;

	// game window setup
	getmaxyx(stdscr, this->_maxH, this->_maxW);
	this->_height = this->_maxH - 2 * y;
	this->_width = this->_maxW - 2 * x;
	this->_win = newwin(this->_height, this->_width, y, x);
	wborder(this->_win, 0, 0, 0, 0, 0, 0, 0, 0);
	wrefresh(this->_win);

	// header window setup
	this->_hH = y - 1;
	this->_hW = this->_maxW - 2 * x;
	this->_header = newwin(this->_hH, this->_hW, 1, x);
	wmove(this->_header, 0, 0);
	waddstr(this->_header, title.c_str());
	wrefresh(this->_header);

	// footer setup
	this->_fH = y - 1;
	this->_fW = this->_maxW - 2 * x;
	this->_footer = newwin(this->_fH, this->_fW, this->_maxH - y, x);
	wborder(this->_footer, 0, 0, 0, 0, 0, 0, 0, 0);

	// game board setup
	this->_board = new AMoving**[this->_width - 4];
	for (int i = 0; i < this->_width - 4; ++i)
		this->_board[i] = new AMoving*[this->_height - 1];
	for (int i = 0; i < this->_width - 4; ++i)
		for (int j = 0; j < this->_height - 1; ++j)
			this->_board[i][j] = 0;
	this->_player = new Player(0, (this->_height - 1) / 2, '>', 1, 1, 1, 1);

	this->_lives = 3;
	this->_isDead = false;

	this->refresh();

}

Game::~Game( void ) {}

void		Game::affScore( void ) const {
	std::string	gameOver[5] = {
		" ,----.                                 ,-----.",
		"'  .-./    ,--,--.,--,--,--. ,---.     '  .-.  ',--.  ,--.,---. ,--.--.",
		"|  | .---.' ,-.  ||        || .-. :    |  | |  | \\  `'  /| .-. :|  .--'",
		"'  '--'  |\\ '-'  ||  |  |  |\\   --.    '  '-'  '  \\    / \\   --.|  |",
		" `------'  `--`--'`--`--`--' `----'     `-----'    `--'   `----'`--'"
	};
	int			ticks = clock();

	werase(this->_win);
	wborder(this->_win, 0, 0, 0, 0, 0, 0, 0, 0);
	for (int i = 0; i < 5; ++i) {
		wmove(this->_win, this->_height / 2 - 2 + i, this->_width / 2 - 36);
		waddstr(this->_win, gameOver[i].c_str());
	}
	wrefresh(this->_win);
	this->_makeFooter(ticks);
}

void		Game::_makeFooter( int ticks ) const {

	std::stringstream ss, ss2;
	double	dms = 1000.0 * ticks / CLOCKS_PER_SEC;
	int		ms = (int) dms % 1000;
	int		sec = (ticks / CLOCKS_PER_SEC) % 60;
	int		min = ((ticks / CLOCKS_PER_SEC) / 60) % 60;
	int		hour = ((ticks / CLOCKS_PER_SEC) / 60) / 60;

	werase(this->_footer);
	wborder(this->_footer, 0, 0, 0, 0, 0, 0, 0, 0);
	ss << hour << ":";
	wmove(this->_footer, this->_fH / 2, this->_fW - (11 + ss.str().length()));
	if (min < 10)
		ss << '0';
	ss << min << ":";
	if (sec < 10)
		ss << '0';
	ss << sec << ":";
	if (ms < 10)
		ss << '0';
	if (ms < 100)
		ss << '0';
	ss << ms;
	waddstr(this->_footer, ss.str().c_str());
	wmove(this->_footer, this->_fH / 2, 2);
	for (int i = 0; i < this->_lives; ++i)
		waddstr(this->_footer, "# ");
	ss2 << this->_score;
	wmove(this->_footer, this->_fH / 2, this->_fW / 2 - ss2.str().length() / 2);
	waddstr(this->_footer, ss2.str().c_str());
	wrefresh(this->_footer);

}

void		Game::_addEnemies( void ) {
	int			rnd = rand() % 100;
	int			line = rand() % (this->_height - 1) + 1;
	std::string	chars = "{[(|I";
	char		c = chars[rand() % 5];
	int			speed = (rand() % 5 + 1) * 2;

	if (rnd == 0)
		this->_board[this->_width - 5][line] = new Grunt(this->_width - 5, line, c, speed, -1, 1, 1, 100);
}

void		Game::_moveObjects( double secs ) {

	AMoving *	temp;

	for (int i = 0; i < this->_width - 4; ++i) {
		for (int j = 0; j < this->_height - 1; ++j) {
			temp = this->_board[i][j];
			if (temp) {
				if ((secs - temp->getTime()) > 1.0 / temp->getSpeed()) {
					temp->setTime(secs);
					this->_horizontalMove(temp);
				}
				AEnemy* e = dynamic_cast<AEnemy *>(temp);
				if (e && rand() % 100 == 0)
				{
					Missile * missile = e->shoot();
					if (missile->getX() > 0)
						this->_board[missile->getX()][missile->getY()] = missile;
					else
						delete missile;
				}
			}
		}
	}

}

void		Game::_renderAll( void ) const {

	AMoving *	temp;

	wmove(this->_win, this->_player->getY(), this->_player->getX() + 2);
	waddch(this->_win, this->_player->getSymbol());
	for (int i = 0; i < this->_width - 4; ++i) {
		for (int j = 0; j < this->_height - 1; ++j) {
			temp = this->_board[i][j];
			if (temp) {
				wmove(this->_win, temp->getY(), temp->getX() + 2);
				waddch(this->_win, temp->getSymbol());
			}
		}
	}

}

bool		Game::refresh( void ) {

	int		ticks = clock();
	double	secs = (double) ticks / (double) CLOCKS_PER_SEC;

	if (!this->_isDead) {
		if (this->_first || (secs - this->_time) > 1.0 / 60.0) {

			this->_addEnemies();

			this->_makeFooter(ticks);
			werase(this->_win);
			wborder(this->_win, 0, 0, 0, 0, 0, 0, 0, 0);
			this->_moveObjects(secs);
			this->_renderAll();
			wrefresh(this->_win);
			this->_time = secs;
			this->_first = false;

		}
	}

	return !this->_isDead;

}

void		Game::_horizontalMove( AMoving * mover ) {

	int	pX = mover->getX();
	int	pY = mover->getY();
	int newX = pX + mover->getDirection();

	if (newX >= 0 && newX < this->_width - 4) {
		this->_board[pX][pY] = 0;
		if (this->_board[newX][pY] == 0) {
			if (this->_player->getX() != newX || this->_player->getY() != pY) {
				this->_board[newX][pY] = mover;
				mover->moveX(newX);
			}
			else
				this->_collision(pX, pY);
		}
		else
			this->_collision(mover, newX, pY);
	}
	else {
		this->_board[pX][pY] = 0;
		delete mover;
	}

}

void		Game::_verticalMove( AMoving * mover ) {

	int	pX = mover->getX();
	int	pY = mover->getY();
	int newY = pY +  mover->getDirection();

	if (newY > 0 && newY < this->_height - 1) {
		this->_board[pX][pY] = 0;
		if (this->_board[pX][newY] == 0) {
			if (this->_player->getX() != pX || this->_player->getY() != newY) {
				this->_board[pX][newY] = mover;
				mover->moveY(newY);
			}
			else
				this->_collision(pX, pY);
		}
		else
			this->_collision(mover, pX, newY);
	}
	else {
		this->_board[pX][pY] = 0;
		delete mover;
	}

}

void		Game::_horizontalMove( Player * mover, int direction ) {

	int	pX = mover->getX();
	int	pY = mover->getY();
	int newX = pX + direction * mover->getSpeed();

	if (newX >= 0 && newX < this->_width - 4) {
		if (this->_board[newX][pY] == 0)
			mover->moveX(newX);
		else
			this->_collision(newX, pY);
	}

}

void		Game::_verticalMove( Player * mover, int direction ) {

	int	pX = mover->getX();
	int	pY = mover->getY();
	int newY = pY + direction * mover->getSpeed();

	if (newY > 0 && newY < this->_height - 1) {
		if (this->_board[pX][newY] == 0)
			mover->moveY(newY);
		else
			this->_collision(pX, newY);
	}

}

void		Game::_collision( AMoving * mover, int x, int y) {
	if (AEnemy* e = dynamic_cast<AEnemy *> (this->_board[x][y]))
		this->_score += e->getPoints();
	delete this->_board[x][y];
	if (AEnemy* e = dynamic_cast<AEnemy *> (mover))
		this->_score += e->getPoints();
	this->_board[x][y] = 0;
	delete mover;
}

void		Game::_collision( int x, int y ) {
	delete this->_board[x][y];
	this->_board[x][y] = 0;
	this->_dead();
}

void		Game::_dead( void )
{
	this->_lives -= 1;
	if (this->_lives <= 0)
		this->_gameOver();
	else
	{
		this->_player->moveX(0);
		this->_player->moveY(this->_height / 2 - 1);
	}
}

void		Game::_gameOver( void )
{
	AMoving* temp;

	for (int i = 0; i < this->_width - 4; ++i) {
		for (int j = 0; j < this->_height - 1; ++j) {
			temp = this->_board[i][j];
			if (temp)
			{
				this->_board[i][j] = 0;
				delete temp;
			}
		}
	}
	delete this->_player;
	this->_isDead = true;

}

void		Game::moveUp( void ) {

	this->_verticalMove(this->_player, -1);

}

void		Game::moveDown( void ) {

	this->_verticalMove(this->_player, 1);

}

void		Game::moveLeft( void ) {

	this->_horizontalMove(this->_player, -1);
	
}

void		Game::moveRight( void ) {

	this->_horizontalMove(this->_player, 1);
	
}

void		Game::shoot( void ) {

	Missile *	missile = this->_player->shoot();

	if (missile->getX() < this->_width - 4)
		this->_board[missile->getX()][missile->getY()] = missile;
	else
		delete missile;

}

Game &		Game::operator=( Game const & rhs ) {
	( void ) rhs;
	return *this;
}