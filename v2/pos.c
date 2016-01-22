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

int			check_space(t_map *map, int i)
{
	int	x;
	int	y;
	int	a;
	int	b;

	x = map->c_pos[0];
	y = map->c_pos[1];
	a = map->tetrilist[i][0];
	b = map->tetrilist[i][1];
	if (map->map[x][y] != '.')
		return (0);
	if (map->map[x + ][y])


}