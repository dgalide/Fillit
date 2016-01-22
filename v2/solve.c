/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:04:24 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/18 20:33:42 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

int			solve(t_map *map)
{
}

int		find(t_map *map, int i)
{
	if (i == map->nb_tetri)
	{
//		ft_putchar('G');
		solution_cpy(map);
		return (1);
	}
	if (map->tetrilist[i][8] == 0)
	{
		while (!check_space(map, map->tetrilist[i]))
		{
			//ft_putchar('A');
			if(update_pos(map) == 0)
			{
			//	ft_putchar('B');
				erase_tetri(map, i - 1);
			//	ft_putchar('C');
				find(map, i);
			}
		}
//		ft_putchar('D');
		put_tetri(map, i);
//		ft_putchar('E');
		update_pos(map);
//		ft_putchar('F');
		find(map, i + 1);
	}
	else
	{
//		ft_putchar('H');
		find(map, i + 1);
	}
	return (0);
}

void		print_solution(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->c_range)
	{
		while (j < map->c_range)
		{
			ft_putchar(map->solution[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}