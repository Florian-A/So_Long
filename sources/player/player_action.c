/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// get action code
int	get_action_keycode(int keycode)
{
	if (keycode == 123 || keycode == 0)
		return (1);
	else if (keycode == 124 || keycode == 2)
		return (2);
	else if (keycode == 126 || keycode == 13)
		return (10);
	else if (keycode == 125 || keycode == 1)
		return (4);
	else if (keycode == 14 || keycode == 82)
		return (5);
	else if (keycode == 49)
		return (10);
	return (0);
}

// set action
void	set_action(int keycode, t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	if (get_action_keycode(keycode) != 5)
	{
		if (p->ac[0] == 0
			|| p->ac[0] == get_action_keycode(keycode))
			p->ac[0] = get_action_keycode(keycode);
		else if (p->ac[1] == 0 || \
			p->ac[1] == get_action_keycode(keycode))
			p->ac[1] = get_action_keycode(keycode);
	}
	else
		p->ac[2] = get_action_keycode(keycode);
	if (p->ac[0] == 1 || p->ac[1] == 1)
		p->direction = 0;
	if (p->ac[0] == 2 || p->ac[1] == 2)
		p->direction = 1;
}

// unset action
void	unset_action(int keycode, t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	if (p->ac[0] == get_action_keycode(keycode))
		p->ac[0] = 0;
	if (p->ac[1] == get_action_keycode(keycode))
		p->ac[1] = 0;
	if (p->ac[0] == 0 && p->ac[1] != 0)
	{
		p->ac[0] = p->ac[1];
		p->ac[1] = 0;
	}
	if (p->ac[2] == get_action_keycode(keycode))
		p->ac[2] = 0;
}

// get text action from action code
char	*get_action(int ac)
{
	if (ac == 1)
		return ("LEFT");
	else if (ac == 2)
		return ("RIGHT");
	else if (ac == 3)
		return ("TOP");
	else if (ac == 4)
		return ("BOTTOM");
	else if (ac == 5)
		return ("ATTAK");
	else if (ac == 10)
		return ("JUMP");
	else
		return ("NULL");
}

// show actions
void	show_action(t_so_long *so_long)
{
	char		*dbg_msg[4];
	t_player	*p;

	p = so_long->player;
	dbg_msg[0] = ft_strjoin("MV ACTION1 : ", get_action(p->ac[0]));
	dbg_msg[1] = ft_strjoin("MV ACTION2 : ", get_action(p->ac[1]));
	dbg_msg[2] = ft_strjoin("ATK ACTION1 : ", \
		get_action(p->ac[2]));
	mlx_string_put(so_long->mlx, so_long->window, \
		20, 53, 11001101, dbg_msg[0]);
	mlx_string_put(so_long->mlx, so_long->window, \
		20, 73, 11001101, dbg_msg[1]);
	mlx_string_put(so_long->mlx, so_long->window, \
		20, 93, 11001101, dbg_msg[2]);
	free(dbg_msg[0]);
	free(dbg_msg[1]);
	free(dbg_msg[2]);
}
