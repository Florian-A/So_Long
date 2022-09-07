/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Player move in horizontal axis
void	player_move_y(t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	if (p->ac[0] == 2)
		p->pp[0] += get_prwc(so_long);
	else if (p->ac[0] == 1)
		p->pp[0] -= get_plwc(so_long);
}

// Player move in vertical axis
void	player_move_z(t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	if (p->ac[0] == 3)
		p->pp[1] -= get_pjwc(so_long);
	else if (p->ac[0] == 4)
		p->pp[1] += get_pdwc(so_long);
}

// Player move in diagonal
void	player_move_d(t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	if ((((p->ac[0] == 10 && p->ac[1] == 1) || \
		(p->ac[0] == 1 && p->ac[1] == 10)) || \
		((p->ac[0] == 10 && p->ac[1] == 2) || (p->ac[0] == 2 && p->ac[1] == 10))
		) && get_pgwc(so_long) == 0)
	{
		p->js = 10;
		if (p->ac[1] == 1)
			p->di = 1;
		else if (p->ac[1] == 2)
			p->di = 2;
	}
	if (p->js > 0 && p->di > 0)
	{
		p->pp[1] -= get_pjwc(so_long);
		if (p->di == 2)
			p->pp[0] += get_prwc(so_long) / 2;
		else if (p->di == 1)
			p->pp[0] -= get_plwc(so_long) / 2;
		p->js--;
		if (p->js == 0)
			p->di = 0;
	}
}

// Player jump in vertical axis
void	player_jump(t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	if ((p->ac[0] == 10 \
		|| p->ac[1] == 10) && p->js == 0 && \
		get_pgwc(so_long) == 0)
		p->js = 10;
	else if (p->js > 0 && p->di == 0)
	{
		p->pp[1] -= get_pjwc(so_long);
		p->js--;
	}
}
