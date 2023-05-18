/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/18 19:35:52 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

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

void	ft_exit(char **matrix, char *msg)
{
	ft_free_arr(matrix);
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	//system("leaks so_long");
	exit(errno);
}

int	main(int ac, char **av)
{
	char	**matrix;

	if (ac != 2)
		return (1);
	matrix = ft_parsing(av[1]);
	ft_get_player_position(matrix);
	ft_init_mlx(matrix);
	ft_print_matrix(matrix);
	ft_free_arr(matrix);
	//system("leaks so_long");
	return (0);
}
