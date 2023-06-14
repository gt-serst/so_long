/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extracting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 12:43:20 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n%s\n", strerror(errno));
		exit(errno);
	}
	return (fd);
}

/*
static int	count_strs(char *argv)
{
	int		fd;
	int		strs;
	char	*line;

	fd = open_fd(argv);
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
	{
		close(fd);
		return (0);
	}
	strs = 1;
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		strs++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (strs);
}
*/
/*
char	**remove_nl(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == '\n')
				map[row][col] = '\0';
			col++;
		}
		row++;
	}
	return (map);
}
*/

void	exit_msg_fd(int fd, char *content, char *line, char *msg)
{
	close(fd);
	if (content)
		free(content);
	if (line)
		free(line);
	ft_printf("Error\n%s", msg);
	exit(EXIT_FAILURE);
}

char	*join_line(char *content, char *line)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (!content || !line)
		return (NULL);
	size = ft_strlen(content) + ft_strlen(line);
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (content[i])
		str[j++] = content[i++];
	i = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(content);
	free(line);
	return (str);
}

char	*get_map(char *argv)
{
	int		fd;
	char	*line;
	char	*content;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	fd = open_fd(argv);
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		exit_msg_fd(fd, content, line, "Empty map\n");
	while (line)
	{
		content = join_line(content, line);
		if (!content)
			exit_msg_fd(fd, content, line, "Couldn't get the map");
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

/*
char	**get_map(char **map, char *argv)
{
	int		row;
	int		fd;
	char	*line;
	int		strs;

	strs = count_strs(argv);
	if (!strs)
		exit_msg(map, "Empty map\n");
	map = malloc(sizeof(char *) * (strs + 1));
	if (!map)
		return (NULL);
	row = 0;
	fd = open_fd(argv);
	line = get_next_line(fd);
	while (line)
	{
		map[row] = line;
		line = get_next_line(fd);
		row++;
	}
	map[row] = 0;
	close(fd);
	return (map);
}
*/
