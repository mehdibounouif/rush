/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_vision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:50:33 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/07 22:50:34 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	count_vision_right(t_Game *g, int row, int col)
{
	int	i;
	int	min;
	int	current;
	int	right;

	right = 1;
	i = col - 1;
	min = g->board[row * g->size + col];
	while (col == g->size - 1 && i >= 0)
	{
		current = g->board[row * g->size + i];
		if (current > min)
		{
			min = current;
			right++;
		}
		i--;
	}
	return (right);
}

int	count_vision_left(t_Game *g, int row, int col, int val)
{
	int	current;
	int	max;
	int	left;
	int	i;

	i = 1;
	left = 1;
	max = g->board[row * g->size + 0];
	while (i <= col)
	{
		current = g->board[row * g->size + i];
		if (g->board[row * g->size + i - 1] == val)
		{
			return (-1);
		}
		if (current > max)
		{
			max = current;
			left++;
		}
		i++;
	}
	return (left);
}

int	count_vision_top(t_Game *g, int row, int col, int val)
{
	int	max;
	int	i;
	int	current;
	int	top;

	top = 1;
	max = g->board[0 * g->size + col];
	i = 1;
	while (i <= row)
	{
		current = g->board[i * g->size + col];
		if (g->board[(i - 1) * g->size + col] == val)
		{
			return (-1);
		}
		if (current > max)
		{
			max = current;
			top++;
		}
		i++;
	}
	return (top);
}

int	count_vision_bot(t_Game *g, int row, int col)
{
	int	i;
	int	current;
	int	bot;
	int	min;

	bot = 1;
	i = row - 1;
	min = g->board[row * g->size + col];
	while (row == g->size - 1 && i >= 0)
	{
		current = g->board[i * g->size + col];
		if (current > min)
		{
			min = current;
			bot++;
		}
		i--;
	}
	return (bot);
}
