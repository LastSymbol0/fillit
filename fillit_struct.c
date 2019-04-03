/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysandule <ysandule@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:06:31 by aillia            #+#    #+#             */
/*   Updated: 2019/03/31 14:53:14 by ysandule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*replace(t_tetrimino *head)
{
	t_tetrimino *cur;

	cur = head;
	while (cur->next != NULL)
	{
		replace_content(cur->content);
		cur = cur->next;
	}
	return (head);
}

void		replace_content(char s[4][4])
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	letter;

	x = replace_find_x(s);
	y = replace_find_y(s);
	i = -1;
	letter = find_letter(s);
	if (x == 0 && y == 0)
		return ;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i][j] != '.')
			{
				s[i][j] = '.';
				s[i - y][j - x] = letter;
			}
		}
	}
}

int			replace_find_x(char s[4][4])
{
	int i;
	int j;
	int x;

	x = 3;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i][j] != '.' && j < x)
				x = j;
		}
	}
	return (x);
}

int			replace_find_y(char s[4][4])
{
	int i;
	int j;
	int y;

	y = 3;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i][j] != '.' && i < y)
				y = i;
		}
	}
	return (y);
}
