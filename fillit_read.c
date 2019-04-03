/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysandule <ysandule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:55:36 by aillia            #+#    #+#             */
/*   Updated: 2019/04/02 14:37:13 by ysandule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*write_to_struct(char **s, t_tetrimino *cur, char letter)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[i][j] == '#')
				cur->content[i][j] = letter;
			else
				cur->content[i][j] = s[i][j];
		}
	}
	return (cur);
}

char		**read_tetrimino(int fd, char **str)
{
	char	**s;
	int		i;
	int		gnl_ret;

	s = (char**)malloc(sizeof(char *) * 4);
	i = -1;
	while ((++i < 4 && (gnl_ret = !(*str) ? get_next_line(fd, str) : 1)))
	{
		if (valid_line(*str) == -1)
			return (NULL);
		s[i] = *str;
		*str = NULL;
	}
	if (gnl_ret != 1)
		return (NULL);
	gnl_ret = get_next_line(fd, str);
	if (*str && *str[0] != '\0')
		return (NULL);
	if (valid_tetrimino(s) == -1)
		return (NULL);
	return (s);
}

void		free_plz(char **s)
{
	int i;

	i = -1;
	while (++i < 4)
		free(s[i]);
	free(s);
}

t_tetrimino	*parser(int fd)
{
	char		letter;
	char		**tetr;
	char		*str;
	t_tetrimino	*cur;
	t_tetrimino	*head;

	head = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	cur = head;
	letter = 'A';
	get_next_line(fd, &str);
	while (1)
	{
		if ((tetr = read_tetrimino(fd, &str)) == NULL)
			return (NULL);
		free(str);
		write_to_struct(tetr, cur, letter);
		free_plz(tetr);
		letter++;
		cur->next = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		cur = cur->next;
		if (get_next_line(fd, &str) == 0)
			break ;
	}
	cur->next = NULL;
	return (replace(head));
}
