/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:09:35 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	is_set(char c,	char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*s2;

	if (!s1)
		return (0);
	s1_len = ft_strlen(s1);
	i = 0;
	j = s1_len;
	while (is_set(s1[i], (char *)set))
		i++;
	while (is_set(s1[--j], (char *)set))
		if (j == 0)
			break ;
	s2_len = (s1_len - i) - (s1_len - j) + 2;
	if (s2_len < 1)
		s2_len = 1;
	s2 = ft_calloc(s2_len, sizeof(char));
	if (!s2)
		return (0);
	ft_strlcpy(s2, (char *)&s1[i], s2_len);
	return (s2);
}
