/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:45:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/12 18:16:57 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_open_fd(char **av)
{
	int	map;

	map = open(av[1], O_RDONLY);
	if (map < 0)
		ft_exit_msg();
	return (map);
}

static int	ft_count_lines(int fd)
{
	int		i;
	int		count_lines;
	char	buf[4096];
	int		len;

	i = 0;
	count_lines = 0;
	len = read(fd, buf, 4096);
	while (len > 0)
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
				count_lines++;
			i++;
		}
		len = read(fd, buf, 4096);
	}
	close(fd);
	return (count_lines);
}

static char	**ft_get_matrix(char **av, int count_lines)
{
	int		i;
	int		map;
	char	*line;
	char	**matrix;

	map = ft_open_fd(av);
	matrix = malloc(sizeof(char *) * (count_lines + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	line = get_next_line(map);
	while (line)
	{
		matrix[i] = line;
		line = get_next_line(map);
		i++;
	}
	matrix[i] = 0;
	close(map);
	return (matrix);
}

char	**ft_parsing(char **av)
{
	int		map;
	int		count_lines;
	char	**matrix;

	map = ft_open_fd(av);
	count_lines = ft_count_lines(map);
	matrix = ft_get_matrix(av, count_lines);
	if (!matrix)
		return (NULL);
	return (matrix);
}
