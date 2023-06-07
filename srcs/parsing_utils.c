/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 11:12:21 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_rows(char **map)
{
	int	count_rows;

	count_rows = 0;
	while (map[count_rows])
		count_rows++;
	return (count_rows);
}

int	check_length(char **map)
{
	int	row;
	int	col;
	int	length;

	length = ft_strlen(map[0]);
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
			col++;
		if (length != col)
			return (0);
		row++;
	}
	return (1);
}

int	check_width(char **map)
{
	int	row;
	int	col;
	int	width;

	width = count_rows(map);
	col = 0;
	while (map[0][col])
	{
		row = 0;
		while (map[row])
			row++;
		if (width != row)
			return (0);
		col++;
	}
	return (1);
}
