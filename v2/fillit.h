/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:18:21 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/20 20:02:45 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
 #define FILLIT_H
 #include <stdlib.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/uio.h>
 #include <unistd.h>
 #include "libft.h"

#define SIZE_BUFF 547

typedef struct	s_map
{
	int		c_range;
	int		m_range;
	int		*c_pos;
	int		nb_tetri;
	int		**tetrilist;
	char	**map;
	char	**solution;
}				t_map;

int				**malloc_list(int nb_tetri);
char 			**buff_to_tab(char *str);
int				range_min(int nb);
int				ischar(char character);
int				ft_neighbor(char **piece);
int				check_1(char *buff, int ret);
void			check(char *str, int ret);
void			relativ_pos(char **piece, t_map *map, int nb); 
void			ft_error(void);
void			xychr(char **piece, int *x, int *y, int c);
void			ft_read(int fd, t_map *map);
void			solution_cpy(t_map *map);
int				update_pos(t_map *map);
int				check_space(t_map *map, int *lst);
void			put_tetri(t_map *map, int i);
void			erase_tetri(t_map *map, int i);

#endif