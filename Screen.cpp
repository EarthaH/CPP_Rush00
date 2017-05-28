/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 00:37:07 by lchimes           #+#    #+#             */
/*   Updated: 2017/05/28 00:37:10 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.hpp"


Screen::Screen() {
	initscr();

	getmaxyx(stdscr, _maxY, _maxX);
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
}

Screen::~Screen() {

}

Screen::Screen(Screen const &obj) {
	this->operator=(obj);
}

Screen &Screen::operator=(Screen const &obj) {
	set_maxX(obj.get_maxX());
	set_maxY(obj.get_maxY());
	return *this;
}

void Screen::sleep(unsigned long int n) {
	clock_t startTime = clock();
	while (clock() - startTime < n) {

	}
}

void Screen::printScore(int score, int life) {
	int bs;
	bs = life + score;
}

bool Screen::gameOver() {
	int maxRow, maxCol;
	char lose[] = "YOU LOST!";
	char startOrQuit[] = "Press 'S' to start and 'Q' to quit.";
	char ch;

	clear();
	getmaxyx(stdscr, maxRow, maxCol);
	drawBorders();
	mvprintw(maxRow / 2, (maxCol - strlen(lose)) / 2, "%s", lose);
	mvprintw((maxRow / 2) + 1, (maxCol - strlen(startOrQuit)) / 2, "%s", startOrQuit);
	for (;;) {
		ch = getch();
		if (ch == 'q' || ch == 'Q') {
			refresh();
			return false;
		} else if (ch == 'S' || ch == 's')
			return true;
	}
}

bool Screen::printMenu() {
	int maxRow, maxCol;
	char startMsg[] = "Welcome to your day of doom!";
	char instruct[] = "Press 'S' to start and 'Q' to quit.";
	int ch;
	refresh();
	getmaxyx(stdscr, maxRow, maxCol);
	drawBorders();
	mvprintw(maxRow / 2, (maxCol - strlen(startMsg)) / 2, "%s", startMsg);
	mvprintw((maxRow / 2) + 1, (maxCol - strlen(instruct)) / 2, "%s", instruct);
	for (;;) {
		ch = getch();
		if (ch == 's')
			return true;
		if (ch == 'q')
			return false;
	}
}

void Screen::screenUpdate(Player *p, Ship s[], GameEntity movingStars[], GameEntity staticStars[],
                          GameEntity playerBullets[]) {
	erase();
	for (int i = 0; i < 50; i++) {
		mvprintw(staticStars[i].get_yPos(), staticStars[i].get_xPos(), staticStars[i].get_dCh());
	}
	for (int i = 0; i < 50; i++)
		mvprintw(movingStars[i].get_yPos(), movingStars[i].get_xPos(), movingStars[i].get_dCh());
	mvprintw(p->get_yPos(), p->get_xPos(), p->get_dCh());
	for (int i = 0; i < 20; i++)
		if (!s[i].is_collided())
			mvprintw(s[i].get_yPos(), s[i].get_xPos(), s[i].get_dCh());
	for (int i = 0; i < 10; i++) {
		if (!playerBullets[i].is_collided())
			mvprintw(playerBullets[i].get_yPos(), playerBullets[i].get_xPos(), playerBullets[i].get_dCh());
	}
	drawBorders();
	refresh();
}


void Screen::drawBorders() {
	int maxRow, maxCol, i;

	getmaxyx(stdscr, maxRow, maxCol);
	for (i = 0; i < maxCol; i++) {
		mvaddch(0, i, '|');
		mvaddch(maxRow - 1, i, '|');
	}
	for (i = 0; i < maxRow; i++) {
		mvaddch(i, 0, '-');
		mvaddch(i, maxCol - 1, '-');
	}
}

//____________________GETTERS AND SETTERS____________________


int Screen::get_maxX() const {
	return _maxX;
}

void Screen::set_maxX(int _maxX) {
	Screen::_maxX = _maxX;
}

int Screen::get_maxY() const {
	return _maxY;
}

void Screen::set_maxY(int _maxY) {
	Screen::_maxY = _maxY;
}

void Screen::loadScreen() {
	int maxRow, maxCol, blockRow, blockCol;
	bool loading;

	getmaxyx(stdscr, maxRow, maxCol);
	drawBorders();
	blockCol = 1;
	blockRow = 1;
	loading = true;
	while (loading) {
		if (blockCol == maxCol - 1)
			blockCol = 1;
		if (blockRow == maxRow - 1)
			blockRow = 1;
		mvaddch(blockRow, blockCol, '#');
		refresh();
		if (blockCol == maxCol - 2 && blockRow == maxRow - 2)
			loading = false;
		blockCol++;
		blockRow++;
		sleep(10);
	}

	refresh();
	mvprintw(31, maxCol / 2 - 27, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	sleep(40000);
	refresh();
	mvprintw(32, maxCol / 2 - 27, "|.......||||||..|||||..||||..|||||||||....||||........|");
	sleep(40000);
	refresh();
	mvprintw(33, maxCol / 2 - 27, "|..||||..||||....||||...||...||||||||..||..|||..|||||||");
	sleep(40000);
	refresh();
	mvprintw(34, maxCol / 2 - 27, "|..||||..|||..||..||||..||..||||||||..||||..||..|||||||");
	sleep(40000);
	refresh();
	mvprintw(35, maxCol / 2 - 27, "|..||||..||..||||..|||..||..||||||||..||||..||..|||||||");
	sleep(40000);
	refresh();
	mvprintw(36, maxCol / 2 - 27, "|..||||..||..||||..||||....|||||||||..||||..||......|||");
	sleep(40000);
	refresh();
	mvprintw(37, maxCol / 2 - 27, "|..||||..||........|||||..||||||||||..||||..||..|||||||");
	sleep(40000);
	refresh();
	mvprintw(38, maxCol / 2 - 27, "|..||||..||..||||..|||||..||||||||||..||||..||..|||||||");
	sleep(40000);
	refresh();
	mvprintw(39, maxCol / 2 - 27, "|..||||..||..||||..|||||..|||||||||||..||..|||..|||||||");
	sleep(40000);
	refresh();
	mvprintw(40, maxCol / 2 - 27, "|.......|||..||||..|||||..||||||||||||....||||..|||||||");
	sleep(40000);
	refresh();
	mvprintw(41, maxCol / 2 - 27, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	sleep(40000);
	refresh();
	mvprintw(42, maxCol / 2 - 27, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	sleep(40000);
	refresh();
	mvprintw(43, maxCol / 2 - 27, "||||||||.......|||||....||||||....||||..|||||..||||||||");
	sleep(40000);
	refresh();
	mvprintw(44, maxCol / 2 - 27, "||||||||..||||..|||..||..||||..||..|||...|||...||||||||");
	sleep(40000);
	refresh();
	mvprintw(45, maxCol / 2 - 27, "||||||||..||||..||..||||..||..||||..||..|...|..||||||||");
	sleep(40000);
	refresh();
	mvprintw(46, maxCol / 2 - 27, "||||||||..||||..||..||||..||..||||..||..||.||..||||||||");
	sleep(40000);
	refresh();
	mvprintw(47, maxCol / 2 - 27, "||||||||..||||..||..||||..||..||||..||..|||||..||||||||");
	sleep(40000);
	refresh();
	mvprintw(48, maxCol / 2 - 27, "||||||||..||||..||..||||..||..||||..||..|||||..||||||||");
	sleep(40000);
	refresh();
	mvprintw(49, maxCol / 2 - 27, "||||||||..||||..||..||||..||..||||..||..|||||..||||||||");
	sleep(40000);
	refresh();
	mvprintw(50, maxCol / 2 - 27, "||||||||..||||..|||..||..||||..||..|||..|||||..||||||||");
	sleep(40000);
	refresh();
	mvprintw(51, maxCol / 2 - 27, "||||||||.......|||||....||||||....||||..|||||..||||||||");
	sleep(40000);
	refresh();
	mvprintw(52, maxCol / 2 - 27, "|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	refresh();
	sleep(500000);
}


