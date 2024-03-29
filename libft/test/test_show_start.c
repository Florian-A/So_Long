/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_show_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtest.h"

void	test_show_start(t_test *test)
{
	if (test->type == 1)
	{
		ft_printf("%s__________________________________________%s", \
		TYEL, TNRM);
		ft_printf("\n%s/////////////// UNIT TESTS ///////////////%s\n", \
		TYEL, TNRM);
		ft_printf("%s¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯%s\n", \
		TYEL, TNRM);
	}
}
