/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:56:25 by lchimes           #+#    #+#             */
/*   Updated: 2017/05/27 21:56:28 by lchimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_H
#define SHIP_H

#include "GameEntity.hpp"

class Ship : public GameEntity
{
public:
	Ship(void);
	Ship(char *c);
	Ship(Ship const & obj);
	Ship & operator=(Ship const & src);
	~Ship(void);
	void initBullets(GameEntity bulletArr[]);
	void shoot(GameEntity bulletArr[]);
};

#endif
