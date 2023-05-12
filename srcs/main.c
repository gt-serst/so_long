/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/12 18:18:41 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_exit_msg()
{
	write(1, "Error\n", 6);
	exit(errno);
}

int	main(int ac, char **av)
{
	int		i;
	char	**matrix;

	if (ac != 2)
		return (1);
	matrix = ft_parsing(av);
	if (!matrix)
		ft_exit_msg();
	i = 0;
	while (matrix[i])
	{
		printf("%s", matrix[i]);
		i++;
	}
	ft_free_arr(matrix);
	return (0);
}
