/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Setting player collision points
void	player_position(t_so_long *so_long)
{
	t_player	*p;

	p = so_long->player;
	p->a[0] = p->pp[0];
	p->a[1] = p->pp[1];
	p->b[0] = p->a[0];
	p->b[1] = p->a[1] + BPX;
	p->c[0] = p->a[0] + BPX;
	p->c[1] = p->a[1];
	p->d[0] = p->a[0] + BPX;
	p->d[1] = p->a[1] + BPX;
}
