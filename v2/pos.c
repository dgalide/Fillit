
#include "fillit.h"
#include <stdio.h>

void		update_pos(t_map *map)
{
	int		x;
	int		y;

	x = map->c_pos[0];
	y = map->c_pos[1];
	while (x < map->c_range)
	{
		while (y < map->c_range)
		{
			if (map->map[x][y] == '.')
			{
				map->c_pos[0] = x;
				map->c_pos[1] = y;
				return ;
			}
			y++;
		}
		x++;
		y = 0;
	}
}

int			check_space(t_map *map, int *lst)
{
	int	x;
	int	y;
	int	a;
	int	b;

	x = map->c_pos[0];
	y = map->c_pos[1];
	a = lst[2];
	b = lst[3];
	printf("x + a = %d ||| y + b = %d\n", (x + a), (y + b));
	if (map->map[(x + a)][(y + b)] == '.')
	{
		a = lst[4];
		b = lst[5];
		printf("x + a = %d ||| y + b = %d\n", (x + a), (y + b));
		if (map->map[(x + a)][(y + b)] == '.')
		{
			a = lst[6];
			b = lst[7];
			printf("x + a = %d ||| y + b = %d\n", (x + a), (y + b));
			if (map->map[(x + a)][(y + b)] == '.')
				return 1;
		}
	}
	printf("A = %d", a);
	return 0;
}