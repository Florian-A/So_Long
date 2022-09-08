/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_collision(char c, int type)
{
	if (type == 1)
	{
		if (c == '1')
			return (1);
		else
			return (0);
	}
	else
	{
		if (c == '0')
			return (1);
		else if (c == '*')
			return (1);
		else if (c == 'C')
			return (1);
		else if (c == 'M')
			return (1);
		else if (c == 'E')
			return (1);
		else
			return (0);
	}
}

// Return the distance between the monster and the nearest obstacle on the right
int	get_mrwc(t_monster *monster, t_so_long *so_long)
{
	int			dist_coll;
	t_monster	*m;

	m = monster;
	if (is_collision(so_long->map[m->c[1] / BPX][m->c[0] / BPX +1], 1))
	{
		if (is_collision(so_long->map[(m->c[1]) / BPX][(m->c[0]) / BPX], 1))
			return (0);
		dist_coll = BPX + (BPX * ((m->c[0]) / BPX) - m->c[0]) - 1;
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	else if (is_collision(so_long->map[m->c[1] / BPX +1][m->c[0] / BPX +1], 0))
	{
		if (is_collision(so_long->map[(m->c[1]) / BPX +1][(m->c[0]) / BPX], 0))
			return (0);
		dist_coll = BPX + (BPX * ((m->c[0]) / BPX) - m->c[0]) - 1;
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	return (MPX);
}

// Return the distance between the monster and the nearest obstacle on the left
int	get_mlwc(t_monster *monster, t_so_long *so_long)
{
	int			dist_coll;
	t_monster	*m;

	m = monster;
	if (is_collision(so_long->map[(m->a[1]) / BPX][(m->a[0]) / BPX -1], 1))
	{
		dist_coll = m->a[0] - (BPX * ((m->a[0]) / BPX));
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	else if (is_collision(so_long->map[(m->a[1]) / BPX +1][(m->a[0]) / BPX -1], \
		0))
	{
		dist_coll = m->a[0] - (BPX * ((m->a[0]) / BPX));
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	return (MPX);
}
