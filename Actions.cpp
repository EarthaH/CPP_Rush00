/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 22:14:34 by lchimes           #+#    #+#             */
/*   Updated: 2017/05/27 22:14:35 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Actions.hpp"

Action::Action() {

}

Action::Action(Action const &obj) {
	this->operator=(obj);
}

Action &Action::operator=(Action const &obj) {
	set_action(obj.get_action());
	return *this;
}

Action::~Action() {

}


void Action::setAction(int ch) {
	if (ch == KEY_LEFT || ch == KEY_RIGHT || ch == KEY_UP || ch == KEY_DOWN || ch == ' '
	    || ch == 'q')
		set_action(ch);
	else
		set_action('p');
}

void Action::checkCollision(Player *p1, Ship s1[], GameEntity playerBullets[]) {
	int y, x;
	for (int i = 0; i < 20; i++) {
		if (!s1[i].is_collided()) {
			if (p1->get_yPos() == s1[i].get_yPos() &&
			    (p1->get_xPos() == s1[i].get_xPos() - 1 || p1->get_xPos() == s1[i].get_xPos())) {
				p1->collided();
				s1[i].collided();
			}
		}
	}
	getmaxyx(stdscr, y, x);
	if (p1->get_yPos() == 0 || p1->get_yPos() == y - 1)
		p1->collided();
	for (int i = 0; i < 20; i++)
		if (!s1[i].is_collided())
			if (s1[i].get_xPos() < -1)
				s1[i].collided();
	for (int i = 0; i < 10; i++) {
		if (!playerBullets[i].is_collided()) {
			for (int j = 0; j < 20; j++) {
				if (!s1[j].is_collided()) {
					if (playerBullets[i].get_yPos() == s1[j].get_yPos()) {
						if (playerBullets[i].get_xPos() == s1[j].get_xPos()
						    || playerBullets[i].get_xPos() == s1[j].get_xPos() - 1
						    || playerBullets[i].get_xPos() == s1[j].get_xPos() - 2) {
							playerBullets[i].set_collided(true);
							s1[j].collided();
						}
					}
				}
			}
			if (playerBullets[i].get_xPos() > x - 1)
				playerBullets[i].set_collided(true);
		}
	}
}

bool Action::applyAction(Player *p, Ship s[], GameEntity movingStars[], GameEntity playerBullets[]) {
	int row, col;
	static bool onOff = true;
	getmaxyx(stdscr, row, col);
	switch (_action) {
		case KEY_LEFT:
			if (p->get_xPos() > 1)
				p->set_xPos(p->get_xPos() - 1);
			break;
		case KEY_RIGHT:
			if (p->get_xPos() < col - 2)
				p->set_xPos(p->get_xPos() + 1);
			break;
		case KEY_UP:
			p->set_yPos(p->get_yPos() - 1);
			break;
		case KEY_DOWN:
			p->set_yPos(p->get_yPos() + 1);
			break;
		case ' ':
			p->shoot(playerBullets);
			break;
		case 'q':
			return (false);
		default:
			break;
	}
	if (onOff) {
		for (int i = 0; i < 50; i++) {
			movingStars[i].set_xPos(movingStars[i].get_xPos() - 1);
			if (movingStars[i].get_xPos() == 0) {
				movingStars[i].set_xPos(col - 1);
				movingStars[i].set_yPos((rand() % (row - 2)) + 1);
			}
		}
		onOff = false;
	} else
		onOff = true;
	for (int i = 0; i < 20; i++) {
		if (!s[i].is_collided())
			s[i].set_xPos(s[i].get_xPos() - 1);
		else if (s[i].get_respawnTime() > 0)
			s[i].set_respawnTime(s[i].get_respawnTime() - 1);
		else if (s[i].get_respawnTime() == 0)
			s[i].set_collided(false);
	}
	for (int i = 0; i < 10; i++) {
		if (!playerBullets[i].is_collided()) {
			playerBullets[i].set_xPos(playerBullets[i].get_xPos() + 3);
		}
	}
	checkCollision(p, s, playerBullets);
	return (true);
}

//_________________________GETTERS AND SETTERS __________________________v

int Action::get_action() const {
	return _action;
}

void Action::set_action(int _action) {
	Action::_action = _action;
}



