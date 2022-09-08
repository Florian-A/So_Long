/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// main player function
void	player(t_so_long *so_long)
{
	so_long->player->lpp[0] = so_long->player->pp[0];
	so_long->player->lpp[1] = so_long->player->pp[1];
	player_jump(so_long);
	player_gravity(so_long);
	player_move_y(so_long);
	player_move_z(so_long);
	player_move_d(so_long);
	player_count_movement(so_long);
	player_draw(so_long);
}
