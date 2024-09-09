/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 22:01:22 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/07 22:59:37 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct Game
{
	int	*board;
	int	*vision;
	int	*nbrs;
	int	size;
}	t_Game;

// solver.c
int		solve(int i, int j, t_Game *g);
int		is_valid_vision(int row, int col, t_Game *g, int val);

// game.c
void	print_board(t_Game *g);
int		init_game(t_Game *g, char *str);
int		fill_game(t_Game *g, char *str);
void	free_game(t_Game *g);

// utils.c
void	ft_putchar(char c);
void	ft_print(char *s);

// main.c
int		count_input(char *str);

// count_vision.c
int		count_vision_right(t_Game *g, int row, int col);
int		count_vision_top(t_Game *g, int row, int col, int val);
int		count_vision_bot(t_Game *g, int row, int col);
int		count_vision_left(t_Game *g, int row, int col, int val);
