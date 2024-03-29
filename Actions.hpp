/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 22:14:27 by lchimes           #+#    #+#             */
/*   Updated: 2017/05/27 22:14:28 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
#define ACTION_H

#include "Player.hpp"

class Action {

public:
	Action();

	Action(Action const &obj);

	Action &operator=(Action const &obj);

	~Action();

	void setAction(int ch);

	int get_action() const;

	void set_action(int _action);

	bool applyAction(Player *p, Ship s[], GameEntity stars[], GameEntity playerBullets[], GameEntity explode[]);

	void checkCollision(Player *p1, Ship s1[], GameEntity playerBullets[]);

private:
	int _action;
};

#endif
