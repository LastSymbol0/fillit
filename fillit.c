/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysandule <ysandule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:55:36 by aillia            #+#    #+#             */
/*   Updated: 2019/04/02 20:37:17 by ysandule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int			fd;
	t_tetrimino	*head;

	if (ac != 2 || ft_strequ(av[1], "-h"))
		write(1, "usage:\n\t./fillit path_to_file\n", 30);
	else
	{
		if (check_double_lf(av[1]) == -1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		if (!(fd = open(av[1], O_RDONLY)))
			write(1, "error\n", 6);
		if ((head = parser(fd)) == NULL)
		{
			write(1, "error\n", 6);
			return (0);
		}
		g_map_size = find_map_size(head);
		while (solve(head) != 1)
			g_map_size++;
	}
	return (0);
}
