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

int gameLoop() {
	int x, y;

	getmaxyx(stdscr, y, x);
	Action act;
	Player *p1 = new Player;
	Ship e1[20];
	GameEntity stars[150];
	GameEntity playerBullets[10];
	GameEntity explode[4];
	GameEntity boss[77];

	boss[0].set_dCh((char *)"/XXXXXXXXXXX\\"); boss[0].set_yPos(10); boss[0].set_xPos(x - 37 - 15);
 	boss[1].set_dCh((char *)"XXXXXXXXXX\\"); boss[1].set_yPos( 11); boss[1].set_xPos(x - 25 - 15);
   boss[2].set_dCh((char *)"XXXX\\"); boss[2].set_yPos( 12); boss[2].set_xPos(x - 21 - 5);
   boss[3].set_dCh((char *)"XXx\\"); boss[3].set_yPos( 13); boss[3].set_xPos(x - 15 - 5);
   boss[4].set_dCh((char *)"XXx\\"); boss[4].set_yPos( 14); boss[4].set_xPos(x - 11 - 5);
   boss[5].set_dCh((char *)"XXx\\"); boss[5].set_yPos( 15); boss[5].set_xPos(x - 10 - 5);
   boss[6].set_dCh((char *)"XXx\\"); boss[6].set_yPos( 16); boss[6].set_xPos(x - 9 - 5);
   boss[7].set_dCh((char *)"XXx\\"); boss[7].set_yPos( 17); boss[7].set_xPos(x - 6 - 5);
   boss[8].set_dCh((char *)"XX\\"); boss[8].set_yPos( 18); boss[8].set_xPos(x - 10 - 5);
   boss[9].set_dCh((char *)"xXX\\"); boss[9].set_yPos( 19); boss[9].set_xPos(x - 5 - 5);
   boss[10].set_dCh((char *)"xXXXx\\"); boss[10].set_yPos( 20); boss[10].set_xPos(x - 4 - 5);
   boss[11].set_dCh((char *)"Xx\\"); boss[11].set_yPos( 21); boss[11].set_xPos(x - 4 - 5);
   boss[12].set_dCh((char *)"xXX\\"); boss[12].set_yPos( 22); boss[12].set_xPos(x - 6 - 5);
   boss[13].set_dCh((char *)"xXX\\"); boss[13].set_yPos( 23); boss[13].set_xPos(x - 2 - 5);
   boss[14].set_dCh((char *)"xXX/"); boss[14].set_yPos( 24); boss[14].set_xPos(x - 2 - 5);
   boss[15].set_dCh((char *)"XXXX/"); boss[15].set_yPos( 25); boss[15].set_xPos(x - 4 - 5);
   boss[16].set_dCh((char *)"XXXXXX/"); boss[16].set_yPos( 26); boss[16].set_xPos(x - 5 - 5);
   boss[17].set_dCh((char *)"XXXXXX/"); boss[17].set_yPos( 27); boss[17].set_xPos(x - 10 - 5);
   boss[18].set_dCh((char *)"XXXXXXX/"); boss[18].set_yPos( 28); boss[18].set_xPos(x - 16 - 5);
   boss[19].set_dCh((char *)"XXXXXXX/"); boss[19].set_yPos( 29); boss[19].set_xPos(x - 19 - 5);
   boss[20].set_dCh((char *)"XXXXX/"); boss[20].set_yPos( 30); boss[20].set_xPos(x - 25 - 5);
   boss[21].set_dCh((char *)"XX/"); boss[21].set_yPos( 31); boss[21].set_xPos(x - 26 - 5);
   boss[22].set_dCh((char *)"XX/"); boss[22].set_yPos( 32); boss[22].set_xPos(x - 31 - 5);
   boss[23].set_dCh((char *)"XX/"); boss[23].set_yPos( 33); boss[23].set_xPos(x - 32 - 5);
   boss[24].set_dCh((char *)"XX/"); boss[24].set_yPos( 34); boss[24].set_xPos(x - 31 - 5);
   boss[25].set_dCh((char *)"XX/"); boss[25].set_yPos( 35); boss[25].set_xPos(x - 34 - 5);
   boss[26].set_dCh((char *)"XX/"); boss[26].set_yPos( 36); boss[26].set_xPos(x - 41 - 5);
   boss[27].set_dCh((char *)"XXX/"); boss[27].set_yPos( 37); boss[27].set_xPos(x - 44 - 5);
   boss[28].set_dCh((char *)"XxxxxXXXX/"); boss[28].set_yPos( 38); boss[28].set_xPos(x - 49 - 5);
   boss[29].set_dCh((char *)"----"); boss[29].set_yPos( 39); boss[29].set_xPos(x - 53 - 5);

   boss[30].set_dCh((char *)"/XXXX"); boss[30].set_yPos( 11); boss[30].set_xPos(x + 15 - 71);
   boss[31].set_dCh((char *)"/XX"); boss[31].set_yPos( 12); boss[31].set_xPos(x + 13 - 71);
   boss[32].set_dCh((char *)"/XX"); boss[32].set_yPos( 13); boss[32].set_xPos(x + 11 - 71);
   boss[33].set_dCh((char *)"/XX"); boss[33].set_yPos( 14); boss[33].set_xPos(x + 9 - 71);
   boss[34].set_dCh((char *)"/XX"); boss[34].set_yPos( 15); boss[34].set_xPos(x + 7 - 71);
   boss[35].set_dCh((char *)"/XX"); boss[35].set_yPos( 16); boss[35].set_xPos(x + 5 - 71);
   boss[36].set_dCh((char *)"/Xx"); boss[36].set_yPos( 17); boss[36].set_xPos(x + 6 - 71);
   boss[37].set_dCh((char *)"\\XX"); boss[37].set_yPos( 18); boss[37].set_xPos(x + 7 - 71);
   boss[38].set_dCh((char *)"\\XX"); boss[38].set_yPos( 19); boss[38].set_xPos(x + 6 - 71);
   boss[39].set_dCh((char *)"\\XX"); boss[39].set_yPos( 20); boss[39].set_xPos(x + 4 - 71);
   boss[40].set_dCh((char *)"\\XX"); boss[40].set_yPos( 21); boss[40].set_xPos(x + 5 - 71);
   boss[41].set_dCh((char *)"/Xx"); boss[41].set_yPos( 22); boss[41].set_xPos(x + 6 - 71);
   boss[42].set_dCh((char *)"\\XX"); boss[42].set_yPos( 23); boss[42].set_xPos(x + 7 - 71);
   boss[43].set_dCh((char *)"\\Xx"); boss[43].set_yPos( 24); boss[43].set_xPos(x + 6 - 71);
   boss[44].set_dCh((char *)"\\Xx"); boss[44].set_yPos( 25); boss[44].set_xPos(x + 7 - 71);
   boss[45].set_dCh((char *)"\\xX"); boss[45].set_yPos( 26); boss[45].set_xPos(x + 6 - 71);
   boss[46].set_dCh((char *)"/xXXX"); boss[46].set_yPos( 27); boss[46].set_xPos(x + 5 - 71);
   boss[47].set_dCh((char *)"/xX"); boss[47].set_yPos( 28); boss[47].set_xPos(x + 3 - 71);
   boss[48].set_dCh((char *)"/xX"); boss[48].set_yPos( 29); boss[48].set_xPos(x + 2 - 71);
   boss[49].set_dCh((char *)"/x"); boss[49].set_yPos( 30); boss[49].set_xPos(x + 3 - 71);
   boss[50].set_dCh((char *)"\\x"); boss[50].set_yPos( 31); boss[50].set_xPos(x + 4 - 71);
   boss[51].set_dCh((char *)"\\x"); boss[51].set_yPos( 32); boss[51].set_xPos(x + 5 - 71);
   boss[52].set_dCh((char *)"\\/"); boss[52].set_yPos( 33); boss[52].set_xPos(x + 12 - 71);
   boss[53].set_dCh((char *)"/xxx"); boss[53].set_yPos( 34); boss[53].set_xPos(x + 4 - 71);
   boss[54].set_dCh((char *)"\\x/"); boss[54].set_yPos( 35); boss[54].set_xPos(x + 5 - 71);
   boss[55].set_dCh((char *)"/xxx"); boss[55].set_yPos( 36); boss[55].set_xPos(x + 7 - 71);
   boss[56].set_dCh((char *)"\\XX"); boss[56].set_yPos( 37); boss[56].set_xPos(x + 8 - 71);

   boss[57].set_dCh((char *)"/Xx\\"); boss[57].set_yPos( 19); boss[57].set_xPos(x + 11 - 71);
   boss[58].set_dCh((char *)"/xXXXX\\"); boss[58].set_yPos( 20); boss[58].set_xPos(x + 10 - 71);
   boss[59].set_dCh((char *)"/xXXXXXXX\\x"); boss[59].set_yPos( 21); boss[59].set_xPos(x + 9 - 71);
   boss[60].set_dCh((char *)"\\xXXXXXXX/"); boss[60].set_yPos( 22); boss[60].set_xPos(x + 10 - 71);
   boss[61].set_dCh((char *)"\\X   x/"); boss[61].set_yPos( 23); boss[61].set_xPos(x + 11 - 71);
   boss[62].set_dCh((char *)"xxxxx/"); boss[62].set_yPos( 24); boss[62].set_xPos(x + 11 - 71);

   boss[63].set_dCh((char *)"\\ /"); boss[63].set_yPos( 32); boss[63].set_xPos(x + 7 - 71);
   boss[64].set_dCh((char *)"\\ /"); boss[64].set_yPos( 32); boss[64].set_xPos(x + 11 - 71);
   boss[65].set_dCh((char *)"/xX"); boss[65].set_yPos( 32); boss[65].set_xPos(x + 16 - 71);
   boss[66].set_dCh((char *)"XXXx"); boss[66].set_yPos( 32); boss[66].set_xPos(x + 20 - 71);

   boss[67].set_dCh((char *)"/X"); boss[67].set_yPos( 33); boss[67].set_xPos(x + 16 - 71);
   boss[68].set_dCh((char *)"XXXxx"); boss[68].set_yPos( 33); boss[68].set_xPos(x + 19 - 71);

   boss[69].set_dCh((char *)"XXXXXXXXXXXX"); boss[69].set_yPos( 26); boss[69].set_xPos(x + 18 - 71);
   boss[70].set_dCh((char *)"XXXX"); boss[70].set_yPos(26); boss[70].set_xPos(x + 21 - 71);

   boss[71].set_dCh((char *)"x  x"); boss[71].set_yPos( 33); boss[71].set_xPos(x + 17 - 71);
   boss[72].set_dCh((char *)"x x"); boss[72].set_yPos( 34); boss[72].set_xPos(x + 16 - 71);
   boss[73].set_dCh((char *)"x x"); boss[73].set_yPos( 35); boss[73].set_xPos(x + 11 - 71);
   boss[74].set_dCh((char *)"\\xxxx"); boss[74].set_yPos( 34); boss[74].set_xPos(x + 8 - 71);
   boss[75].set_dCh((char *)"x x"); boss[75].set_yPos( 29); boss[75].set_xPos(x + 6 - 71);
   boss[76].set_dCh((char *)"xxxx"); boss[76].set_yPos( 29); boss[76].set_xPos(x + 10 - 71);

   for (int i = 0; i < 77; i++)
   {
	   boss[i].set_collided(false);
   }
	Screen screen;
	bool stillPlaying = true;
	int ch, score;

	timeout(0);
	p1->initBullets(playerBullets);
	for (int i = 0; i < 50; i++){

	}
	while (stillPlaying) {
		ch = getch();
		act.setAction(ch);
		stillPlaying = act.applyAction(p1, e1, stars, playerBullets, explode);
		screen.screenUpdate(p1, e1, stars, playerBullets, explode, boss);
		if (p1->is_collided())
			stillPlaying = false;
		sleep(40000);
	}
	score = p1->get_score();
	delete p1;
	return (score);
}

int main(void) {
	srand(time(0));
	bool stillPlaying = 1;
	int score;
	Screen *screen = new Screen;
	screen->loadScreen();
	while (stillPlaying == 1) {
		stillPlaying = screen->printMenu();
		if (stillPlaying) {
			score = gameLoop();
			stillPlaying = screen->gameOver();
		}
	}
	screen->loadScreen();
	endwin();
	delete screen;
	return (0);
}