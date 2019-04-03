/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysandule <ysandule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:46:28 by aillia            #+#    #+#             */
/*   Updated: 2019/04/02 20:39:11 by ysandule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_strdel_ret(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
		return (1);
	}
	return (0);
}

char			*ft_strjoin_upd(char *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	r = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (r == NULL)
		return (NULL);
	while (s1[j] != '\0')
		r[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		r[i++] = s2[j++];
	r[i] = '\0';
	free(s1);
	return (r);
}

static	void	set_line_and_rewrite(char **line, char **s, char **buff)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	ft_strdel(buff);
	while (s[0][i] != '\n' && s[0][i] != '\0')
		i++;
	if (s[0][i] == '\0')
		line[0] = ft_strdup(s[0]);
	else
	{
		tmp = ft_strdup(s[0] + i + 1);
		line[0] = (char *)malloc(sizeof(char) * i + 1);
		line[0][i] = '\0';
		while (--i >= 0)
			line[0][i] = s[0][i];
	}
	free(s[0]);
	s[0] = tmp;
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[4096];
	char		*buff;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000 || fd >= 4096)
		return (-1);
	buff = ft_strnew(BUFF_SIZE + 1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	while (!ft_strchr(s[fd], '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if (ret < 0)
			return (-1);
		if (ret == 0)
		{
			if ((s[fd] == NULL || s[fd][0] == '\0') && ft_strdel_ret(&buff))
				return (0);
			break ;
		}
		s[fd] = ft_strjoin_upd(s[fd], buff);
	}
	set_line_and_rewrite(line, &s[fd], &buff);
	return (1);
}
