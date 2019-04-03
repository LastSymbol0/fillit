/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysandule <ysandule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:26:37 by aillia            #+#    #+#             */
/*   Updated: 2019/04/02 14:09:37 by ysandule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_double_lf(char *s)
{
	int		fd;
	char	buff[550];
	int		l_byte;

	fd = open(s, O_RDONLY);
	l_byte = read(fd, buff, 550);
	if (l_byte > 546)
		return (-1);
	if (buff[l_byte - 2] == '\n' && buff[l_byte - 1] == '\n')
		return (-1);
	return (1);
}

char	find_letter(char s[4][4])
{
	int		i;
	int		j;
	char	letter;

	i = -1;
	letter = '.';
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i][j] != '.')
			{
				letter = s[i][j];
				break ;
			}
		}
	}
	return (letter);
}

void	fill_map(char map[g_map_size][g_map_size])
{
	int i;
	int j;

	i = -1;
	while (++i < g_map_size)
	{
		j = -1;
		while (++j < g_map_size)
		{
			map[i][j] = '.';
		}
	}
}

void	print_map(char map[g_map_size][g_map_size])
{
	int i;
	int j;

	i = -1;
	while (++i < g_map_size)
	{
		j = -1;
		while (++j < g_map_size)
		{
			write(1, &map[i][j], 1);
		}
		write(1, "\n", 1);
	}
}

int		find_map_size(const t_tetrimino *head)
{
	int			i;
	int			n;
	t_tetrimino	*cur;

	n = 1;
	i = 0;
	cur = (t_tetrimino *)head;
	while (cur->next != NULL)
	{
		cur = cur->next;
		i += 4;
	}
	while (n * n < i)
		n++;
	return (n);
}
