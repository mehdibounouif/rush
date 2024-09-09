/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:38:53 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/07 22:38:55 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_board(t_Game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->size)
	{
		j = 0;
		while (j < g->size)
		{
			ft_putchar(g->board[i * g->size + j] + '0');
			if (j != g->size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	fill_game(t_Game *g, char *str)
{
	int	i;
	int	k;
	int	l;

	l = 0;
	k = 0;
	i = 0;
	while (str[i])
	{
		g->nbrs[l] = 1;
		g->board[l++] = 0;
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		if (str[i] - '0' >= 1 && str[i] - '0' <= g->size)
			g->vision[k++] = str[i] - '0';
		else
			return (0);
		i++;
	}
	return (1);
}

int	init_game(t_Game *g, char *str)
{
	g->vision = (int *)malloc(sizeof(int *) * (g->size * g->size));
	g->board = (int *)malloc(sizeof(int *) * (g->size * g->size));
	g->nbrs = (int *)malloc(sizeof(int *) * (g->size * g->size));
	if (g->vision == NULL || g->board == NULL || g->nbrs == NULL)
	{
		free_game(g);
		return (0);
	}
	if (fill_game(g, str) == 0)
	{
		free_game(g);
		return (0);
	}
	return (1);
}

void	free_game(t_Game *g)
{
	if (g->vision)
		free(g->vision);
	if (g->board)
		free(g->board);
	if (g->nbrs)
		free(g->nbrs);
}
