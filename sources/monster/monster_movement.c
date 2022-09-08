/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	monster_move_dir(t_monster *m, t_so_long *so_long)
{
	int			dist;

	if (m->mi > 4)
	{
		m->mi = 0;
		if (m->direction == 1)
		{
			dist = get_mrwc(m, so_long);
			m->pp[0] = m->pp[0] + dist;
			if (m->pp[0] > m->init_p[0] + (BPX * 2) || dist == 0)
				m->direction = 0;
		}
		else
		{
			dist = get_mlwc(m, so_long);
			m->pp[0] = m->pp[0] - dist;
			if (m->pp[0] < m->init_p[0] - (BPX * 2) || dist == 0)
				m->direction = 1;
		}
	}
	m->mi++;
}

void	monster_move(t_so_long *so_long)
{
	t_list		*lst;
	t_monster	*m;

	lst = so_long->monsters;
	while (lst)
	{
		m = ((t_monster *)lst->content);
		monster_position(m);
		if (m->move == 1)
			monster_move_dir(m, so_long);
		lst = lst->next;
	}
}
