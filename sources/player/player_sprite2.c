/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Return player jumb sprite
int	player_jumb_sprite(int *last_anim, t_so_long *so_long)
{
	static int	i;

	if (so_long->player->direction == 0)
	{
		if (so_long->player->js > 1)
			i = 39;
		else if (so_long->player->js <= 1)
			i = 40;
	}
	else
	{
		if (so_long->player->js > 1)
			i = 12;
		else if (so_long->player->js <= 1)
			i = 13;
	}
	*last_anim = 1;
	return (i);
}

// Return player attack sprite
int	player_attack_sprite(int *last_anim, t_so_long *so_long)
{
	static int	i;

	if (so_long->player->direction == 0)
	{
		if (*last_anim != 2)
			i = 46;
		else if (i > 45 && i < 49)
			i++;
		else
			i = 46;
	}
	else
	{
		if (*last_anim != 2)
			i = 19;
		else if (i > 18 && i < 22)
			i++;
		else
			i = 19;
	}
	*last_anim = 2;
	return (i);
}

// Return player walk sprite
int	player_walk_sprite(int *last_anim, t_so_long *so_long)
{
	static int	i;

	if (so_long->player->direction == 0)
	{
		if (*last_anim != 3)
			i = 35;
		else if (i > 34 && i < 38)
			i++;
		else
			i = 35;
	}
	else
	{
		if (*last_anim != 3)
			i = 8;
		else if (i > 7 && i < 11)
			i++;
		else
			i = 8;
	}
	*last_anim = 3;
	return (i);
}

// Return player hurt sprite
int	player_hurt_sprite(int *last_anim, t_so_long *so_long)
{
	static int	i;

	if (so_long->player->direction == 0)
	{
		if (*last_anim != 6)
			i = 50;
		else if (i > 49 && i < 53)
			i++;
		else
			i = 50;
	}
	else
	{
		if (*last_anim != 6)
			i = 23;
		else if (i > 22 && i < 26)
			i++;
		else
			i = 23;
	}
	*last_anim = 6;
	return (i);
}

// Return player down sprite
int	player_down_sprite(int *last_anim, t_so_long *so_long)
{
	static int	i;

	if (so_long->player->direction == 0)
		i = 45;
	else
		i = 18;
	*last_anim = 4;
	return (i);
}
