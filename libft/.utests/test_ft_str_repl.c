/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_replace_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ███████ <███████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:40:56 by ███████           #+#    #+#             */
/*   Updated: 2022/10/09 13:41:46 by ███████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utest.h"

static int	test_ft_str_repl1(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("Cette phrase ne veut absolument rien dire mais c'est absolument \
	pas grave");
	if (!s1)
		return (-1);
	s2 = s1;
	s1 = ft_str_repl(s1, "absolument", "totalement");
	if (!s1)
		return (-1);
	free(s2);
	if (ft_strcmp(s1, "Cette phrase ne veut totalement rien dire mais c'est absolument \
	pas grave") != 0)
	{
		free(s1);
		return (-1);
	}
	free(s1);
	return (0);
}

static int	test_ft_str_repl2(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("Bob");
	if (!s1)
		return (-1);
	s2 = s1;
	s1 = ft_str_repl(s1, "Bob", "Sandy");
	if (!s1)
		return (-1);
	free(s2);
	if (ft_strcmp(s1, "Sandy") != 0)
	{
		free(s1);
		return (-1);
	}
	free(s1);
	return (0);
}

static int	test_ft_str_repl3(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("test");
	if (!s1)
		return (-1);
	s2 = s1;
	s1 = ft_str_repl(s1, "test", "");
	if (!s1)
		return (-1);
	free(s2);
	if (ft_strcmp(s1, "") != 0)
	{
		free(s1);
		return (-1);
	}
	free(s1);
	return (0);
}

static int	test_ft_str_repl4(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup("Que recherche un développeur qui cherche à se marier ? \
	=> Réponse");
	if (!s1)
		return (-1);
	s2 = s1;
	s1 = ft_str_repl(s1, "Réponse", "Une fille en C");
	if (!s1)
		return (-1);
	free(s2);
	if (ft_strcmp(s1, "Que recherche un développeur qui cherche à se marier ? \
	=> Une fille en C") != 0)
	{
		free(s1);
		return (-1);
	}
	free(s1);
	return (0);
}

int	test_ft_str_repl(void)
{
	if (test_ft_str_repl1() == -1)
		return (-1);
	if (test_ft_str_repl2() == -1)
		return (-1);
	if (test_ft_str_repl3() == -1)
		return (-1);
	if (test_ft_str_repl4() == -1)
		return (-1);
	return (0);
}
