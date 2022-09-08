/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Draw the player block on the screen
void	player_draw(t_so_long *so_long)
{
	int			screen_pp[2];
	t_player	*p;

	p = so_long->player;
	screen_pp[1] = p->pp[1] + so_long->po[1];
	screen_pp[0] = p->pp[0] + so_long->po[0];
	if (p->pp[1] < (64 * 2))
		so_long->po[1] = 0;
	else if (screen_pp[1] > (512 + 48))
		so_long->po[1] = -p->pp[1] + (64 * 8) + 48;
	else if (screen_pp[1] < 128)
		so_long->po[1] = -p->pp[1] + (64 * 2);
	if (p->pp[0] < (64 * 2))
		so_long->po[0] = 0;
	else if (screen_pp[0] > (1088 + 76))
		so_long->po[0] = -p->pp[0] + (64 * 17) + 76;
	else if (screen_pp[0] < 128)
		so_long->po[0] = -p->pp[0] + (64 * 2);
	mlx_put_image_to_window(so_long->mlx, so_long->window,
		get_player_sprite(so_long),
		p->pp[0] + so_long->po[0] + so_long->go[0], \
		p->pp[1] + so_long->po[1] + so_long->go[1]);
}
