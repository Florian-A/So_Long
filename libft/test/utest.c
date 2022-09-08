/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtest.h"

void	utest(int is_error, char *s, t_test *test)
{
	test->nb_tests++;
	if (is_error == -1)
	{
		ft_printf("%s %s[FAIL]%s \n", s, TRED, TNRM);
		test->nb_errors++;
	}
	else
	{
		ft_printf("%s %s[SUCCESS]%s \n", s, TGRN, TNRM);
		test->nb_success++;
	}
}
