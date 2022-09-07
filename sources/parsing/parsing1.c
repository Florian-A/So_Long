/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <falonso@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:27:36 by f██████           #+#    #+#             */
/*   Updated: 2022/09/07 12:13:52 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	limit_args(int argc, char *argv[])
{
	if (argc == 3 && argv[2] && ft_strcmp(argv[2], "DEBUG=1") == 0)
		return (1);
	else if (argc == 3 && argv[2] && ft_strcmp(argv[2], "DEBUG=0") == 0)
		return (1);
	else if (argc != 2)
		return (0);
	return (1);
}

int	open_map(char *relative_path, t_so_long *so_long)
{
	int	path_len;

	path_len = ft_strlen(relative_path);
	if (path_len < 4)
		return (0);
	if (ft_strcmp(&relative_path[path_len - 4], ".ber") != 0)
		return (0);
	so_long->map_fd = open(relative_path, O_RDONLY);
	if (so_long->map_fd < 0)
		return (0);
	return (1);
}

int	fill_lst(t_so_long *so_long)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(so_long->map_fd);
		if (line == NULL)
		{
			if (so_long->gw == -1)
				return (0);
			return (1);
		}
		if (so_long->gw == -1)
			so_long->gw = ft_strlen(line) - 1;
		if (so_long->lst_map == NULL)
			so_long->lst_map = ft_lstnew(line);
		else
			ft_lstadd_back(&so_long->lst_map, ft_lstnew(line));
	}
	return (1);
}

int	convert_lst(t_so_long *so_long)
{
	t_list	*lst;
	int		i;

	so_long->gh = ft_lstsize(so_long->lst_map);
	if (so_long->gh < 3)
		return (0);
	so_long->map = ft_calloc(so_long->gh +1, sizeof(char *));
	if (!so_long->map)
		exit(EXIT_FAILURE);
	lst = so_long->lst_map;
	i = 0;
	while (lst)
	{
		so_long->map[i] = ft_strdup(lst->content);
		if (!so_long->map[i])
			exit(EXIT_FAILURE);
		i++;
		lst = lst->next;
	}
	so_long->gw = ft_strlen(so_long->map[0]);
	if (so_long->gw < 4)
		return (0);
	return (1);
}

int	size_check(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[i])
	{
		if (i > so_long->gh)
			return (0);
		if (i + 1 == so_long->gh && \
		(int)ft_strlen(so_long->map[i]) == so_long->gw - 1)
			return (1);
		if ((int)ft_strlen(so_long->map[i]) != so_long->gw)
			return (0);
		i++;
	}
	return (1);
}
