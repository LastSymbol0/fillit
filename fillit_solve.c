/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysandule <ysandule@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:43:18 by ysandule          #+#    #+#             */
/*   Updated: 2019/03/31 14:00:29 by ysandule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_tetramino(char map[g_map_size][g_map_size], char letter)
{
	int i;
	int j;

	i = -1;
	while (++i < g_map_size)
	{
		j = -1;
		while (++j < g_map_size)
		{
			if (map[i][j] == letter)
				map[i][j] = '.';
		}
	}
}

int		put_to_map(char map[g_map_size][g_map_size],
			t_tetrimino *tetr, int i, int j)
{
	int i_1;
	int j_1;

	i_1 = -1;
	while (++i_1 < 4)
	{
		j_1 = -1;
		while (++j_1 < 4)
		{
			if (tetr->content[i_1][j_1] != '.')
			{
				if (i + i_1 < g_map_size && j + j_1 < g_map_size
								&& map[i + i_1][j + j_1] == '.')
					map[i + i_1][j + j_1] = tetr->content[i_1][j_1];
				else
				{
					del_tetramino(map, find_letter(tetr->content));
					return (-1);
				}
			}
		}
	}
	return (1);
}

int		solve_main(char map[g_map_size][g_map_size], t_tetrimino *tetr)
{
	int i;
	int j;
	int ret;

	i = -1;
	ret = -1;
	if (tetr->next == NULL)
		return (1);
	while (++i < g_map_size)
	{
		j = -1;
		while (++j < g_map_size)
		{
			if (put_to_map(map, tetr, i, j) == 1)
				ret = solve_main(map, tetr->next);
			if (ret == 1)
				return (1);
			del_tetramino(map, find_letter(tetr->content));
		}
	}
	return (-1);
}

int		solve(t_tetrimino *head)
{
	t_tetrimino *tetr;
	char		matrix[g_map_size][g_map_size];

	tetr = head;
	fill_map(matrix);
	if (solve_main(matrix, tetr) == -1)
		return (0);
	print_map(matrix);
	return (1);
}
