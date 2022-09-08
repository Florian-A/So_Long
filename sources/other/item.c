/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Get the sprite that corresponds to the correct animation step
int	*get_item_sprite(t_so_long *so_long)
{
	static int	arr_pos;
	static int	anim_inter;

	if (anim_inter >= so_long->nc * 5)
	{
		anim_inter = 0;
		if (arr_pos < 4)
			arr_pos++;
		else
			arr_pos = 0;
	}
	else
		anim_inter++;
	return (so_long->cs[arr_pos]);
}

// Displays an item block
static void	draw_item(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i < so_long->gh)
	{
		j = 0;
		while (j < so_long->gw)
		{
			if (so_long->map[i][j] == 'C')
				draw_block(j * BPX + so_long->po[0],
					i * BPX + so_long->po[1], get_item_sprite(so_long),
					so_long);
			j++;
		}
		i++;
	}
}

// Action triggered during collision with the player
static void	item_action(t_so_long *so_long)
{
	so_long->nc--;
}

// Collision system with the player
static void	item_collision(t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	if (so_long->map[(p->a[1] + HPX) / BPX][(p->a[0] + HPX) / BPX] == 'C')
	{
		so_long->map[(p->a[1] + HPX) / BPX][(p->a[0] + HPX) / BPX] = '0';
		item_action(so_long);
	}
	else if (so_long->map[(p->b[1] - HPX) / BPX][(p->b[0] + HPX) / BPX] == 'C')
	{
		so_long->map[(p->b[1] + HPX) / BPX][(p->b[0] + HPX) / BPX] = '0';
		item_action(so_long);
	}
	else if (so_long->map[(p->a[1] + HPX) / BPX][(p->c[0] - HPX) / BPX] == 'C')
	{
		so_long->map[(p->a[1] + HPX) / BPX][(p->c[0] - HPX) / BPX] = '0';
		item_action(so_long);
	}
	else if (so_long->map[(p->d[1] - HPX) / BPX][(p->c[0] - HPX) / BPX] == 'C')
	{
		so_long->map[(p->d[1] - HPX) / BPX][(p->d[0] - HPX) / BPX] = '0';
		item_action(so_long);
	}
}

// Meta function for items
void	item(t_so_long *so_long)
{
	draw_item(so_long);
	item_collision(so_long);
}
