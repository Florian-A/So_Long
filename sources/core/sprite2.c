/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2023/03/06 14:15:02 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_sprite_type_png(int i, char *p, int sprite_type,
t_so_long *so_long)
{
	int		d;

	d = BPX;
	if (sprite_type == 1)
		so_long->ps[i - 1] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 2)
		so_long->ms[i - 1] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 3)
		so_long->gs[i - 1] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 4)
		so_long->cs[i - 1] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 5)
		so_long->os[i - 1] = mlx_png_file_to_image(so_long->mlx, p, &d, &d);
}

void	load_sprite_type_xpm(int i, char *p, int sprite_type,
t_so_long *so_long)
{
	int		d;

	d = BPX;
	if (sprite_type == 1)
		so_long->ps[i - 1] = mlx_xpm_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 2)
		so_long->ms[i - 1] = mlx_xpm_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 3)
		so_long->gs[i - 1] = mlx_xpm_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 4)
		so_long->cs[i - 1] = mlx_xpm_file_to_image(so_long->mlx, p, &d, &d);
	else if (sprite_type == 5)
		so_long->os[i - 1] = mlx_xpm_file_to_image(so_long->mlx, p, &d, &d);
}
