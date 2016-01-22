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
	find(map, 0);
	return (0);
}

int		find(t_map *map, int i)
{
	if (map->placed_tetri == map->nb_tetri)
	{
		solution_cpy(map);
		return (1);
	}
	if (map->tetrilist[i][8] == 0)
	{
		ft_putchar('A');
		if (check_space(map, map->tetrilist[i]) == 1)
		{
			ft_putchar('B');
			put_tetri(map, i);
			return (find(map, i + 1));
		}
		else
		{
			ft_putchar('C');
			while (update_pos(map) != 0)
			{
				ft_putchar('D');
				map->c_pos[1]++;
				if (check_space(map, map->tetrilist[i]) == 1)
				{
					ft_putchar('E');
					put_tetri(map, i);
					return (find(map, (i + 1)));
				}
			}
			erase_tetri(map, (i - 1));
			ft_error();
			return(find(map, i));
		}

	}
	else
		return(find(map, i + 1));
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
