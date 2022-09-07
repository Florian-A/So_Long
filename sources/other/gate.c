/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Get the sprite that corresponds to the correct animation step
int	*get_gate_sprite(t_so_long *so_long)
{
	static int	arr_pos;
	static int	anim_inter;

	if (anim_inter == 7)
	{
		anim_inter = 0;
		if (arr_pos < 3 && so_long->nc == 0)
			arr_pos++;
	}
	else
		anim_inter++;
	return (so_long->gs[arr_pos]);
}

// Displays an draw block
static void	draw_gate(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->gh)
	{
		j = 0;
		while (j < so_long->gw)
		{
			if (so_long->map[i][j] == 'E')
				draw_block(j * BPX + so_long->po[0],
					i * BPX + so_long->po[1], get_gate_sprite(so_long),
					so_long);
			j++;
		}
		i++;
	}
}

// End-game action when all collectibles have been picked up
static void	gate_action(t_so_long *so_long)
{
	if (so_long->nc == 0)
	{
		ft_printf("Success !");
		mlx_destroy_window(so_long->mlx, so_long->window);
		exit(EXIT_SUCCESS);
	}
}

// Collisions between the gate and the player
static void	gate_collision(t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	if (so_long->map[(p->a[1] + HPX) / BPX][(p->a[0] + HPX) / BPX] == 'E')
		gate_action(so_long);
	else if (so_long->map[(p->b[1] - HPX) / BPX][(p->b[0] + HPX) / BPX] == 'E')
		gate_action(so_long);
	else if (so_long->map[(p->a[1] + HPX) / BPX][(p->c[0] - HPX) / BPX] == 'E')
		gate_action(so_long);
	else if (so_long->map[(p->d[1] - HPX) / BPX][(p->c[0] - HPX) / BPX] == 'E')
		gate_action(so_long);
}

// Meta function for gate
void	gate(t_so_long *so_long)
{
	draw_gate(so_long);
	gate_collision(so_long);
}
