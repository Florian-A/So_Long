/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_show_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtest.h"

void	test_show_result(t_test *test)
{
	ft_printf("_________________________________________\n\n");
	ft_printf("> Total tests : %d\n", test->nb_tests);
	ft_printf("%s> Success : %d%s\n", TGRN, test->nb_success, TNRM);
	ft_printf("%s> Errors : %d%s\n", TRED, test->nb_errors, TNRM);
	ft_printf("%s__________________________________________%s\n", TYEL, TNRM);
	if (test->nb_errors == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
