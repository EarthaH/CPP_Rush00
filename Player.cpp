/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:56:20 by lchimes           #+#    #+#             */
/*   Updated: 2017/05/27 21:56:21 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(void) {
	_dCh = (char *) ">]]]}>";
	_score = 0;
	_lives = 3;
	_xPos = 10;
	_yPos = 10;
	_collided = false;
	_lostlife = false;
}

Player::Player(char *c) {
	_dCh = c;
	_score = 0;
	_lives = 3;
	_xPos = 10;
	_yPos = 10;
	_collided = false;
	_lostlife = false;
}

Player::Player(const Player &obj) {
	this->operator=(obj);
}

Player &Player::operator=(Player const &obj) {
	set_dCh(obj.get_dCh());
	set_xPos(obj.get_xPos());
	set_yPos(obj.get_yPos());
	set_lives(obj.get_lives());
	set_score(obj.get_score());
	return *this;
}

Player::~Player(void) {

}

void Player::collided() {
	int y, x;
	getmaxyx(stdscr, y, x);
	_lives--;
	_lostlife = true;
	if (_lives == 0)
		set_collided(true);
}

//____________________GETTERS AND SETTERS______________________

int Player::get_score() const {
	return _score;
}

void Player::set_score(int _score) {
	Player::_score = _score;
}

int Player::get_lives() const {
	return _lives;
}

void Player::set_lives(int _lives) {
	Player::_lives = _lives;
}

int Player::get_lostlife() const {
	return _lostlife;
}

void Player::set_lostlife(int _lostlife) {
	Player::_lostlife = _lostlife;
}
