/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_interaction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	monster_player_action(t_monster *m, t_so_long *so_long)
{
	if (so_long->player->a[0] > m->a[0])
		so_long->player->direction = 0;
	else
		so_long->player->direction = 1;
	so_long->player->tl = 50;
	m->td = 15;
	m->alive = 0;
}

static void	monster_action(t_monster *m, t_so_long *so_long)
{
	m->move = 0;
	so_long->player->tl--;
	if (m->ta > 0)
		m->ta--;
	if (m->td > 0)
		m->td--;
	if (so_long->player->nl < 1)
	{
		mlx_destroy_window(so_long->mlx, so_long->window);
		ft_printf("You loose the game !\n");
		exit(EXIT_SUCCESS);
	}
	if (so_long->player->tl < 1)
	{
		ft_printf("You loose 1 life !\n");
		so_long->player->tl = 50;
		so_long->player->nl--;
		m->ta = 20;
	}
	else if (so_long->player->ac[2] == 5)
		monster_player_action(m, so_long);
}

void	monster_interaction(t_so_long *so_long)
{
	t_list		*lst;
	t_monster	*m;
	t_player	*p;

	lst = so_long->monsters;
	while (lst)
	{
		m = ((t_monster *)lst->content);
		p = so_long->player;
		if ((((p->a[0] > m->a[0] && p->a[0] < m->c[0]) || \
			(p->c[0] > m->a[0] && p->c[0] < m->c[0])) && \
			p->a[1] < m->b[1] && p->b[1] > m->a[1]) && \
			(m->alive == 1 || m->td > 0))
		{
			if (m->a[0] > p->a[0])
				m->direction = 0;
			else
				m->direction = 1;
			monster_action(m, so_long);
		}
		else
			m->move = 1;
		lst = lst->next;
	}
}
