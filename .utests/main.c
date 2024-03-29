/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:04:58 by f██████           #+#    #+#             */
/*   Updated: 2023/03/08 18:33:19 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

void	test_block1(t_test *test)
{
	utest(test_null(), "null", test);
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
