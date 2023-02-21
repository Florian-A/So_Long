/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_del(char c, char d)
{
	if (c == d)
		return (1);
	return (0);
}

static int	arr_len(char *str, char charset)
{
	int		i;
	int		arr_ln;

	i = 0;
	arr_ln = 0;
	while (str[i++])
		if (!is_del(str[i], charset))
			break ;
	if (i == ((int)ft_strlen(str)))
	{
		if (str[0] == charset)
			return (0);
		else
			return (1);
	}
	i = 0;
	if (!is_del(str[0], charset) && str[0] != '\0')
		arr_ln++;
	while (str[i++])
		if ((is_del(str[i], charset) && !is_del(str[i + 1], charset)
				&& str[i + 1] != '\0' ))
			arr_ln++;
	if (arr_ln == 0)
		return (1);
	return (arr_ln);
}

static void	fill_arr(char const *s, char c, int len, char **s_splited)
{
	int		i;
	int		j;
	int		k;
	char	*pnt;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (is_del(s[i], c))
			i++;
		j = i;
		while (!is_del(s[i], c) && s[i] != '\0' )
			i++;
		if (k != len)
		{
			pnt = ft_calloc(i - j + 1, sizeof(char));
			if (!pnt)
				ft_arr2dfree((void **)s_splited);
			ft_strlcpy(pnt, &s[j], i - j + 1);
			s_splited[k++] = pnt;
		}
	}
	s_splited[len] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**s_splited;
	int		len;

	if (!s)
		return (0);
	len = arr_len((char *)s, c);
	s_splited = ft_calloc((len + 1), sizeof(char *));
	if (!s_splited)
		return (0);
	fill_arr(s, c, len, s_splited);
	return (s_splited);
}
