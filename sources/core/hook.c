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
	if (keycode != 53 && keycode != 65307)
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

void	hook_register(t_so_long *so_long)
{
	if (ft_strcmp(OS, "linux") == 0)
	{
		mlx_hook(so_long->window, 17, 1L << 0, close_hook, so_long);
		mlx_hook(so_long->window, 2, 1L << 0, keydown_hook, so_long);
		mlx_hook(so_long->window, 3, 1L << 1, keyup_hook, so_long);
	}
	else if (ft_strcmp(OS, "mac") == 0)
	{
		mlx_hook(so_long->window, 17, 1L << 0, close_hook, so_long);
		mlx_hook(so_long->window, 2, 0, keydown_hook, so_long);
		mlx_key_hook(so_long->window, keyup_hook, so_long);
	}
}
