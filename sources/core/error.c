/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	sl_error(int error_n, t_so_long *so_long)
{
	(void)so_long;
	if (error_n == 1)
		ft_dprintf(2, "Error: You must indicate only one map path !\n");
	if (error_n == 2)
		ft_dprintf(2, "Error: Unable to open the map !\n");
	if (error_n == 3)
		ft_dprintf(2, "Error: The map is not in a valid format !\n");
	if (error_n == 4)
		ft_dprintf(2, "Error: A sprite could not be opened !\n");
	exit(EXIT_FAILURE);
}
