/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysandule <ysandule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:13:24 by aillia            #+#    #+#             */
/*   Updated: 2019/03/31 17:58:56 by ysandule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"

typedef struct			s_tetrimino
{
	char				content[4][4];
	struct s_tetrimino	*next;
}						t_tetrimino;
int						g_map_size;

# define BUFF_SIZE 4

t_tetrimino				*parser(int fd);
t_tetrimino				*write_to_struct(char **s,
								t_tetrimino *cur, char letter);
char					**read_tetrimino(int fd, char **str);
void					free_plz(char	**s);

t_tetrimino				*replace(t_tetrimino *head);
void					replace_content(char s[4][4]);
int						replace_find_x(char s[4][4]);
int						replace_find_y(char s[4][4]);

int						valid_line(char *s);
int						valid_tetrimino(char **s);
int						check_con(char **s, int i, int j);

int						solve(t_tetrimino *head);
int						solve_main(char map[g_map_size][g_map_size],
												t_tetrimino *tetr);
int						put_to_map(char map[g_map_size][g_map_size],
									t_tetrimino *tetr, int i, int j);
void					del_tetramino(char map[g_map_size][g_map_size],
											char letter);

int						get_next_line(const int fd, char **line);
char					*ft_strjoin_upd(char *s1, char const *s2);
int						ft_strdel_ret(char **as);

int						find_map_size(const t_tetrimino *head);
void					fill_map(char map[g_map_size][g_map_size]);
void					print_map(char map[g_map_size][g_map_size]);
char					find_letter(char s[4][4]);
int						check_double_lf(char *s);

char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *str1, const char *str2);
void					ft_strdel(char **as);
char					*ft_strdup(const char *src);
int						ft_strequ(char const *s1, char const *s2);
size_t					ft_strlen(const char *str);
char					*ft_strnew(size_t size);

#endif
