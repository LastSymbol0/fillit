/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysandule <ysandule@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:34:44 by aillia            #+#    #+#             */
/*   Updated: 2019/03/31 13:53:49 by ysandule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_line(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != '#' && s[i] != '.')
			return (-1);
	}
	if (i != 4)
		return (-1);
	return (1);
}

int		valid_tetrimino(char **s)
{
	int i;
	int j;
	int con;
	int h;

	h = 0;
	con = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i][j] != '#' && s[i][j] != '.')
				return (-1);
			if (s[i][j] == '#' && h++ != -1)
				con += check_con(s, i, j);
		}
		if (s[i][j] != '\0')
			return (-1);
	}
	if ((con == 6 || con == 8) && h == 4)
		return (1);
	return (-1);
}

int		check_con(char **s, int i, int j)
{
	int con;

	con = 0;
	if (j != 3 && s[i][j + 1] == '#')
		con++;
	if (i != 3 && s[i + 1][j] == '#')
		con++;
	if (j != 0 && s[i][j - 1] == '#')
		con++;
	if (i != 0 && s[i - 1][j] == '#')
		con++;
	return (con);
}
