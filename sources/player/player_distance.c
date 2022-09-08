/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Return the distance between the player and the nearest obstacle on the right
int	get_prwc(t_so_long *so_long)
{
	int			dist_coll;
	t_player	*p;
	char		**m;

	p = so_long->player;
	m = so_long->map;
	if (m[(p->c[1] + HPX + EHPX) / BPX][(p->c[0]) / BPX + 1] == '1' ||
	m[(p->d[1]) / BPX][(p->d[0]) / BPX +1] == '1')
	{
		if (m[(p->c[1] + HPX) / BPX][(p->c[0] - HPX) / BPX] == '1' ||
			m[p->d[1] / BPX][(p->d[0] - HPX) / BPX] == '1')
			return (-(HPX + 10));
		dist_coll = BPX + (BPX * ((p->c[0]) / BPX) - p->c[0]) - 1;
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	if (m[(p->c[1] + HPX + EHPX) / BPX][(p->c[0] - HPX + EHPX) / BPX] == '1' ||
	m[p->d[1] / BPX][(p->d[0] - HPX + EHPX) / BPX] == '1')
		return (-(HPX + EHPX + 5));
	return (MPX);
}

// Return the distance between the player and the nearest obstacle on the left
int	get_plwc(t_so_long *so_long)
{
	int			dist_coll;
	t_player	*p;
	char		**m;

	p = so_long->player;
	m = so_long->map;
	if (m[(p->a[1] + HPX + EHPX) / BPX][(p->a[0]) / BPX -1] == '1' ||
	m[(p->b[1]) / BPX][(p->b[0]) / BPX -1] == '1')
	{
		if (m[(p->a[1] + HPX) / BPX][(p->a[0] + HPX) / BPX] == '1' ||
		m[p->b[1] / BPX][(p->b[0] + HPX) / BPX] == '1')
			return (-(HPX + 10));
		dist_coll = p->a[0] - (BPX * ((p->a[0]) / BPX));
		if (dist_coll > MPX)
			return (MPX);
		return (dist_coll);
	}
	if (m[(p->a[1] + HPX + EHPX) / BPX][(p->a[0] + HPX + EHPX) / BPX] == '1' ||
	m[p->b[1] / BPX][(p->b[0] + HPX + EHPX) / BPX] == '1')
		return (-(HPX + EHPX + 5));
	return (MPX);
}

// Return the distance between the player and the nearest obstacle on the down 
// (ground)
int	get_pgwc(t_so_long *so_long)
{
	int			dist_coll;
	t_player	*p;

	p = so_long->player;
	if (so_long->map[(p->b[1]) / BPX +1][(p->b[0] + HPX) / BPX] == '1' ||
	so_long->map[(so_long->player->d[1]) / BPX +1]
	[(p->d[0] - HPX) / BPX] == '1')
	{
		dist_coll = (BPX * ((p->b[1]) / BPX +1)) - p->b[1] -1;
		if (dist_coll > GPX)
			return (GPX);
		return (dist_coll);
	}
	return (GPX);
}

// Return the distance between the player and the nearest obstacle on the down
int	get_pdwc(t_so_long *so_long)
{
	int			dist_coll;
	t_player	*p;

	p = so_long->player;
	if (so_long->map[(p->b[1]) / BPX +1][(p->b[0] + HPX) / BPX] == '1' ||
	so_long->map[(so_long->player->d[1]) / BPX +1]
	[(p->d[0] - HPX) / BPX] == '1')
	{
		dist_coll = (BPX * ((p->b[1]) / BPX +1)) - p->b[1] -1;
		if (dist_coll > DPX)
			return (DPX);
		return (dist_coll);
	}
	return (DPX);
}

// Return the distance between the player and the nearest obstacle on the top
// (jump)
int	get_pjwc(t_so_long *so_long)
{
	int			dist_coll;
	t_player	*p;

	p = so_long->player;
	if (so_long->map[(p->a[1] + 1) / BPX -1][(p->a[0] + HPX) / BPX] == '1' ||
	so_long->map[(p->c[1] + 1) / BPX - 1][(p->c[0] - HPX) / BPX] == '1')
	{
		dist_coll = p->b[1] - (BPX * ((p->b[1] + 1) / BPX)) - 1 + 2;
		if (dist_coll > JPX)
			return (JPX);
		return (dist_coll);
	}
	if (so_long->map[(p->a[1]) / BPX][(p->a[0] + HPX) / BPX] == '1' ||
	so_long->map[(p->c[1]) / BPX][(p->c[0] - HPX) / BPX] == '1')
		return (-(HPX));
	return (JPX);
}
