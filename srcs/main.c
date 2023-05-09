/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/09 17:46:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit_msg()
{
	write(1, "Error\n", 6);
	exit(errno);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	ft_parsing(av);
	//system("leaks so_long");
	return (0);
}
