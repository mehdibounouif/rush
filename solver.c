/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:08:49 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/08 11:37:40 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_valid_vision(int row, int col, t_Game *g, int val)
{
	int	top;
	int	bot;
	int	left;
	int	right;

	left = count_vision_left(g, row, col, val);
	right = count_vision_right(g, row, col);
	if (left > g->vision[2 * g->size + row] || left == -1)
		return (0);
	if (col == g->size - 1
		&& (right != g->vision[3 * g->size + row]
			|| left != g->vision[2 * g->size + row]))
		return (0);
	top = count_vision_top(g, row, col, val);
	bot = count_vision_bot(g, row, col);
	if (top > g->vision[0 * g->size + col] || top == -1)
		return (0);
	if (row == g->size - 1
		&& (bot != g->vision[1 * g->size + col]
			|| top != g->vision[0 * g->size + col]))
		return (0);
	return (1);
}

void	set_next(int *next_i, int next_j, int i)
{
	if (next_j == 0)
		*next_i = i + 1;
	else
		*next_i = i;
}

int	solve(int i, int j, t_Game *g)
{
	int	n;
	int	next_i;

	n = 1;
	if (i == g->size)
		return (1);
	while (n <= g->size)
	{
		if (g->nbrs[i * g->size + n - 1])
		{
			g->board[i * g->size + j] = n;
			g->nbrs[i * g->size + n - 1] = 0;
			if (is_valid_vision(i, j, g, n))
			{
				set_next(&next_i, (j + 1) % g->size, i);
				if (solve(next_i, (j + 1) % g->size, g))
					return (1);
			}
			g->board[i * g->size + j] = 0;
			g->nbrs[i * g->size + n - 1] = 1;
		}
		n++;
	}
	return (0);
}
