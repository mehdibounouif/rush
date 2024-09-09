/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:30:57 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/07 22:33:47 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_input(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i + 1) % 2 == 0 && str[i] != ' ')
		{
			return (-1);
		}
		if ((i + 1) % 2 == 1 && (str[i] >= '0' && str[i] <= '9'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	check_error(int argc, char **argv, int *count)
{
	if (argc != 2)
	{
		ft_print("invalid number of args\n");
		return (0);
	}
	*count = count_input(argv[1]);
	if (*count == -1)
	{
		ft_print("Invalid input data\n");
		return (0);
	}
	if (*count % 4 != 0)
	{
		ft_print("data must make perfect square\n");
		return (0);
	}
	if (*count / 4 < 4 || *count / 4 > 9)
	{
		ft_print("data must be in range 4*4 - 9*9\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		count;
	t_Game	g;

	if (!check_error(argc, argv, &count))
		return (1);
	g.size = count / 4;
	if (!init_game(&g, argv[1]))
	{
		return (1);
	}
	if (solve(0, 0, &g))
	{
		print_board(&g);
	}
	else
	{
		ft_print("can't solve\n");
	}
}
