/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/03/06 09:50:58 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Initialization of the t_so_long structure
void	init_s_so_long(char *argv[], t_so_long *so_long)
{
	so_long->mlx = mlx_init();
	so_long->lm = 0;
	so_long->gw = -1;
	so_long->gh = -1;
	if (argv[2] && ft_strcmp(argv[2], "DEBUG=1") == 0)
		so_long->dbg = 1;
	else
		so_long->dbg = 0;
	so_long->player = ft_calloc(sizeof(t_player), 1);
	if (!so_long->player)
		exit(EXIT_FAILURE);
	so_long->player->js = 0;
	so_long->window = mlx_new_window(so_long->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
		WINDOW_TITLE);
	so_long->po[0] = 0;
	so_long->po[1] = 0;
	so_long->nm = 0;
	so_long->lst_map = NULL;
	so_long->monsters = NULL;
}

// Parsing initialization
int	init_map(int argc, char *argv[], t_so_long *so_long)
{
	if (!limit_args(argc, argv))
		sl_error(1, so_long);
	if (!open_map(argv[1], so_long))
		sl_error(2, so_long);
	if (!fill_lst(so_long))
		sl_error(3, so_long);
	if (!convert_lst(so_long))
		sl_error(3, so_long);
	if (!size_check(so_long))
		sl_error(3, so_long);
	if (!allowed_char(so_long))
		sl_error(3, so_long);
	if (!sides_is_wall(so_long))
		sl_error(3, so_long);
	if (!required_char(so_long))
		sl_error(3, so_long);
	return (1);
}

// Player initialization
int	init_player(t_so_long *so_long)
{
	int		i;
	int		j;

	i = 0;
	so_long->player->tl = 50;
	so_long->player->nl = NB_LIFE;
	so_long->player->direction = 1;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'P')
			{
				so_long->player->pp[0] = j * BPX;
				so_long->player->pp[1] = i * BPX - 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_camera(t_so_long *so_long)
{
	so_long->go[0] = 0;
	so_long->go[1] = 0;
	if (so_long->gw < 15)
		so_long->go[0] = (14 - so_long->gw) / 2 * BPX + 30;
	if (so_long->gh < 8)
		so_long->go[1] = (7 - so_long->gh) / 2 * BPX + 35;
}
