/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	keydown_hook(int keycode, t_so_long *so_long)
{
	set_action(keycode, so_long);
	return (0);
}

int	keyup_hook(int keycode, t_so_long *so_long)
{
	if (keycode != 53)
		unset_action(keycode, so_long);
	else
		close_hook(0, so_long);
	return (0);
}

int	close_hook(int keycode, t_so_long *so_long)
{
	if (keycode == 0)
		mlx_destroy_window(so_long->mlx, so_long->window);
	exit(EXIT_SUCCESS);
	return (0);
}
