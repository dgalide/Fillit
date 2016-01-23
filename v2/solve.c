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
	ft_printtab(map->map);
	ft_putchar('\n');
	int	j;
	int	rvalue;
	
	j = 0;
	printf("i :%d\n", i);
	/*if ()
	{
		rvalue = -3;
		return (0);
	}*/
	if (map->placed_tetri == map->nb_tetri)
	{
		printf("\npassage final\n");
		solution_cpy(map);
		printf("\nprinttab:\n");
		ft_printtab(map->map);
		return (1);
	}
	printf("%d\n", map->tetrilist[i][8]);
	if (map->tetrilist[i][8] == 0)
	{
		ft_putchar('A');
		if (check_space(map, map->tetrilist[i]) == 1)
		{
			ft_putchar('B');
			ft_putchar('\n');
			put_tetri(map, i);
			update_pos(map);
			while (map->tetrilist[j][8] == 1 && j < map->nb_tetri - 1)
			{
				printf("%d\n", j);
				j++;
			}
			return (find(map, j));
		}
		else
		{
			ft_putchar('C');
			while (update_pos(map) != 0)
			{
				ft_putchar('D');
				if (check_space(map, map->tetrilist[i]) == 1)
				{
					ft_putstr("E\n");
					put_tetri(map, i);
					ft_putchar('\n');
					return (find(map, (i + 1)));
				}
					map->c_pos[1]++;
			}
			ft_putchar ('\n');
			erase_tetri(map, (i - 1));
			update_pos(map);
			return(find(map, i));
		}
	}
	else
		return(find(map, i + 1));
	return (rvalue);
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
