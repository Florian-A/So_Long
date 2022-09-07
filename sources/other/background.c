/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Displays a background block
static void	draw_background(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->gh)
	{
		j = 0;
		while (j < so_long->gw)
		{
			if (so_long->map[i][j] == '0' || so_long->map[i][j] == 'M'
			|| so_long->map[i][j] == 'P' || so_long->map[i][j] == 'C' )
				draw_block(j * BPX + so_long->po[0],
					i * BPX + so_long->po[1], so_long->os[0],
					so_long);
			j++;
		}
		i++;
	}
}

// Meta function for background
void	background(t_so_long *so_long)
{
	draw_background(so_long);
}
