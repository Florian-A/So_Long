/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/02/23 07:01:06 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// General loop of the game which will be executed at best every 15ms
static int	game_loop_bonus(t_so_long *so_long)
{
	long long	now;
	long long	diff_millisecs;

	now = millitimestamp();
	diff_millisecs = now - so_long->lm;
	if (diff_millisecs > 15)
	{
		fps(so_long);
		mlx_clear_window(so_long->mlx, so_long->window);
		player_position(so_long);
		background(so_long);
		wall(so_long);
		item(so_long);
		gate(so_long);
		monster(so_long);
		player(so_long);
		if (so_long->dbg)
			show_debug(so_long);
		show_hud(so_long);
	}
	return (1);
}

// General loop of the game which will be executed when possible
static int	game_loop_mandatory(t_so_long *so_long)
{
	mlx_clear_window(so_long->mlx, so_long->window);
	player_position(so_long);
	background(so_long);
	wall(so_long);
	item(so_long);
	gate(so_long);
	player(so_long);
	return (1);
}

int	key_hook(void)
{
	ft_printf("Hello from key_hook!\n");
	return (0);
}

// Initialization of the player/monster/scenery of the game and the MLX
int	main(int argc, char *argv[], char **env)
{
	t_so_long	so_long;

	(void)env;
	init_s_so_long(argv, &so_long);
	init_map(argc, argv, &so_long);
	init_sprites(&so_long);
	init_player(&so_long);
	init_camera(&so_long);
	analyse_monster(&so_long);
	mlx_key_hook(so_long.window, key_hook, NULL);
	//mlx_hook(so_long.window, 17, 1L << 0, key_hook, NULL);
	//mlx_hook(so_long.window, 17, 1L << 0, close_hook, &so_long);
	//mlx_hook(so_long.window, 2, 0, keydown_hook, &so_long);
	//mlx_key_hook(so_long.window, keyup_hook, &so_long);
	if (so_long.bonus == 1)
		mlx_loop_hook(so_long.mlx, game_loop_bonus, &so_long);
	else
		mlx_loop_hook(so_long.mlx, game_loop_mandatory, &so_long);
	mlx_loop(so_long.mlx);
	exit(EXIT_SUCCESS);
}
