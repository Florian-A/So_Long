/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2022/09/08 10:48:45 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

void	test_block1(t_test *test)
{
	utest(test_ft_strlen(), "ft_strlen", test);
	utest(test_ft_atoi(), "ft_atoi", test);
	utest(test_ft_atol(), "ft_atol", test);
	utest(test_ft_bzero(), "ft_bzero", test);
	utest(test_ft_calloc(), "ft_calloc", test);
	utest(test_ft_isalnum(), "ft_isalnum", test);
}

int	main(void)
{
	t_test	test;

	test.type = 1;
	test_init_struct(&test);
	test_show_start(&test);
	test_block1(&test);
	test_show_result(&test);
}
