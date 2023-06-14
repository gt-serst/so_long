/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extracting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:17 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 15:42:25 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_msg_fd(int fd, char *content, char *line, char *msg)
{
	if (fd)
		close(fd);
	if (content)
		free(content);
	if (line)
		free(line);
	ft_printf("Error\n%s\n", msg);
	exit(errno);
}

char	*join_line(int fd, char *content, char *line)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (!content || !line)
		exit_msg_fd(fd, content, line, "Couldn't get the map");
	size = ft_strlen(content) + ft_strlen(line);
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		exit_msg_fd(fd, content, line, "Couldn't get the map");
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
	char	*content;
	char	*line;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit_msg_fd(fd, content, line, strerror(errno));
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		exit_msg_fd(fd, content, line, "Empty map");
	while (line)
	{
		content = join_line(fd, content, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}
