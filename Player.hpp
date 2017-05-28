/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:56:25 by lchimes           #+#    #+#             */
/*   Updated: 2017/05/27 21:56:28 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.hpp"

class Player : public Ship
{
public:
	Player(void);
	Player(char *c);
	Player(Player const & obj);
	Player & operator=(Player const & obj);
	~Player(void);

	int get_score() const;
	void set_score(int _score);
	int get_lives() const;
	void set_lives(int _lives);

private:
	int _score;
	int _lives;
};

#endif
