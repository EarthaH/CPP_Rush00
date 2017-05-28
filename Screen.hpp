/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 00:37:14 by lchimes           #+#    #+#             */
/*   Updated: 2017/05/28 00:37:15 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <iostream>
#include "Player.hpp"

class Screen {

public:
	Screen();

	~Screen();

	Screen(Screen const &obj);

	Screen &operator=(Screen const &obj);

	void sleep(unsigned long int n);

	void printScore(int score, int life);

	void screenUpdate(Player *p, Ship s[], GameEntity movingStars[], GameEntity staticStars[],
	                  GameEntity playerBullets[]);

	void drawBorders();

	bool gameOver();

	int get_maxX() const;

	void set_maxX(int _maxX);

	int get_maxY() const;

	void set_maxY(int _maxY);

	bool printMenu();

	void loadScreen();

private:
	int _maxX;
	int _maxY;
};

#endif
