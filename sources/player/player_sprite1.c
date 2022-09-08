/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Return player failling sprite
int	player_failling_sprite(int *last_anim, t_so_long *so_long)
{
	static int	i;

	if (so_long->player->direction == 0)
		i = 44;
	else
		i = 17;
	*last_anim = 5;
	return (i);
}

// Return player stay sprite
int	player_stay_sprite(int *last_anim, t_so_long *so_long)
{
	static int	i;

	if (so_long->player->direction == 0)
	{
		if (*last_anim != 7)
			i = 27;
		else if (i > 26 && i < 34)
			i++;
		else
			i = 27;
	}
	else
	{
		if (*last_anim != 7)
			i = 0;
		else if (i > -1 && i < 7)
			i++;
		else
			i = 0;
	}
	*last_anim = 7;
	return (i);
}

// Return sprite depending on the player's state
static int	player_sprite_pos(int atk_progress, int hurt_progress,
int *last_anim, t_so_long *so_long)
{
	if (so_long->player->js != 0)
		return (player_jumb_sprite(last_anim, so_long));
	else if (atk_progress > 0)
		return (player_attack_sprite(last_anim, so_long));
	else if (hurt_progress > 0)
		return (player_hurt_sprite(last_anim, so_long));
	else if (so_long->player->ac[0] == 2 || so_long->player->ac[1] == 2 || \
	so_long->player->ac[0] == 1 || so_long->player->ac[1] == 1)
		return (player_walk_sprite(last_anim, so_long));
	else if ((so_long->player->ac[0] == 4 || so_long->player->ac[1] == 4) && \
	get_pgwc(so_long) > 0)
		return (player_down_sprite(last_anim, so_long));
	else if (so_long->player->js == 0 && get_pgwc(so_long) > 0)
		return (player_failling_sprite(last_anim, so_long));
	else
		return (player_stay_sprite(last_anim, so_long));
}

// Get the sprite that corresponds to the correct animation step
int	*get_player_sprite(t_so_long *so_long)
{
	static int	arr_pos;
	static int	last_anim;
	static int	anim_inter;
	static int	atk_progress;
	static int	hurt_progress;

	if (so_long->player->ac[2] == 5)
		atk_progress = 5;
	if (so_long->player->tl == 1)
		hurt_progress = 5;
	if (anim_inter == 5)
	{
		anim_inter = 0;
		if (atk_progress > 0)
			atk_progress--;
		if (hurt_progress > 0)
			hurt_progress--;
		arr_pos = player_sprite_pos(atk_progress, hurt_progress, \
		&last_anim, so_long);
	}
	else
		anim_inter++;
	return (so_long->ps[arr_pos]);
}
