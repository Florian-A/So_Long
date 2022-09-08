/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_count_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// Count player movement
void	player_count_movement(t_so_long *so_long)
{
	if (so_long->player->lpp[0] != so_long->player->pp[0])
	{
		so_long->nm++;
		if (so_long->bonus == 0)
			ft_printf("Movement : %d \n", so_long->nm);
		return ;
	}
	if (so_long->player->lpp[1] != so_long->player->pp[1])
	{
		so_long->nm++;
		if (so_long->bonus == 0)
			ft_printf("Movement : %d \n", so_long->nm);
		return ;
	}
}
