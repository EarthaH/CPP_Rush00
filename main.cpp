/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 23:16:35 by lchimes           #+#    #+#             */
/*   Updated: 2017/05/27 23:16:36 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Actions.hpp"
#include "Player.hpp"
#include "Ship.hpp"
#include "Screen.hpp"
#include <ctime>

void sleep(unsigned long int n) {
	clock_t startTime = clock();
	while (clock() - startTime < n) {
	}
}

void gameLoop() {
	Action act;
	Player *p1 = new Player;
	Ship e1[20];
	GameEntity staticStars[50];
	GameEntity movingStars[50];
	GameEntity playerBullets[10];
	Screen screen;
	bool stillPlaying = true;
	int ch;

	timeout(0);
	p1->initBullets(playerBullets);
	for (int i = 0; i < 50; i++){

	}
	while (stillPlaying) {
		ch = getch();
		act.setAction(ch);
		stillPlaying = act.applyAction(p1, e1, movingStars, playerBullets);
		screen.screenUpdate(p1, e1, movingStars, staticStars, playerBullets);
		if (p1->is_collided() == 1)
			stillPlaying = false;
		sleep(40000);
	}
	delete p1;
}

int main(void) {
	srand(time(0));
	bool stillPlaying = 1;
	Screen *screen = new Screen;
	screen->loadScreen();
	while (stillPlaying == 1) {
		stillPlaying = screen->printMenu();
		if (stillPlaying) {
			gameLoop();
			stillPlaying = screen->gameOver();
		}
	}
	screen->loadScreen();
	endwin();
	delete screen;
	return (0);
}