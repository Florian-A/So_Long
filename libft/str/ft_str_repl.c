/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_repl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:27:36 by ███████           #+#    #+#             */
/*   Updated: 2023/03/08 18:50:17 by f██████          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_str_repl(char *str, char *old_word, char *new_word)
{
	int		i;
	char	*s1;
	char	*s2;

	i = ft_strnstr_i(str, old_word, ft_strlen(str));
	s1 = ft_strndup(str, i);
	if (!s1)
		return (NULL);
	s2 = ft_strjoin(s1, new_word);
	if (!s2)
		return (NULL);
	free(s1);
	i = i + ft_strlen(old_word);
	s1 = ft_strjoin(s2, &str[i]);
	if (!s1)
		return (NULL);
	free(s2);
	return (s1);
}
