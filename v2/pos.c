
#include "fillit.h"
#include <stdio.h>

int			update_pos(t_map *map)
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
				return 1;
			}
			y++;
		}
		x++;
		y = 0;
	}
	return (0);
}

int			check_space(t_map *map, int *lst)
{
	int	x;
	int	y;
	int	a;
	int	b;

	x = map->c_pos[0];
	y = map->c_pos[1];
	a = lst[0];
	b = lst[1];
	if ((((x + a) < map->c_range) && ((y + b) < map->c_range)) && map->map[(x + a)][(y + b)] != '.')
		return 0;
	a = lst[2];
	b = lst[3];
//	printf("%d ||| %d\n", (x + a), (y + b));
	if ((((x + a) < map->c_range) && ((y + b) < map->c_range)) && map->map[(x + a)][(y + b)] == '.')
	{
		a = lst[4];
		b = lst[5];
//		printf("%d ||| %d\n", (x + a), (y + b));
		if ((((x + a) < map->c_range) && ((y + b) < map->c_range)) && map->map[(x + a)][(y + b)] == '.')
		{
			a = lst[6];
			b = lst[7];
//			printf("%d ||| %d\n", (x + a), (y + b));
			if ((((x + a) < map->c_range) && ((y + b) < map->c_range)) && map->map[(x + a)][(y + b)] == '.')
				return 1;
		}
	}
	return 0;
}

void		put_tetri(t_map *map, int i)
{
	int		x;
	int		y;
	int		a;
	int		b;

	x = map->c_pos[0];
	y = map->c_pos[1];
	a = map->tetrilist[i][0];
	b = map->tetrilist[i][1];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][2];
	b = map->tetrilist[i][3];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][4];
	b = map->tetrilist[i][5];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][6];
	b = map->tetrilist[i][7];
	map->map[x + a][y + b] = (char)(i + 65);
	map->tetrilist[i][8] = 1;
}

void		erase_tetri(t_map *map, int i)
{
	int		x;
	int		y;
	int		a;
	int		b;

	xychr(map->map, &x, &y, (i + 65));
	a = map->tetrilist[i][0];
	b = map->tetrilist[i][1];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][2];
	b = map->tetrilist[i][3];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][4];
	b = map->tetrilist[i][5];
	map->map[x + a][y + b] = (char)(i + 65);
	a = map->tetrilist[i][6];
	b = map->tetrilist[i][7];
	map->map[x + a][y + b] = (char)(i + 65);
	map->tetrilist[i][8] = 0;
}