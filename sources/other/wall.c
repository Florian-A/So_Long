/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Displays a wall block
static void	draw_wall(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->gh)
	{
		j = 0;
		while (j < so_long->gw)
		{
			if (so_long->map[i][j] == '1')
				draw_block(j * BPX + so_long->po[0],
					i * BPX + so_long->po[1], so_long->os[1],
					so_long);
			j++;
		}
		i++;
	}
}

// Meta function for walls
void	wall(t_so_long *so_long)
{
	draw_wall(so_long);
}
