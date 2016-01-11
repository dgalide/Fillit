/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 18:45:03 by dgalide           #+#    #+#             */
/*   Updated: 2016/01/11 19:53:06 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_neighbor(char **piece, int column, int line)
{
	int			l;

	l = 0;
	if (piece[column][line + 1] == '#')
		l++;	
	if (piece[column][line - 1] == '#')
		l++;
	if (piece[column + 1][line] == '#')
		l++;
	if (piece[column - 1][line] == '#')
		l++;
	return (l);
}

int				check_line(char *line)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != '.' || line[i] != '#')
			return (0);
		if (line[4] != '\n')
			return (0)
		if (line[i] == '.' || line[i] == '#')
			j++;
		i++;
	}
	if (j != 4)
		return (0);
	else
		return (1);
}

int				check_validity(char **piece)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		if (ft_check_line(piece[i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (piece[i][j])
	{
		if (piece[i][j] == '#')
			k += ft_neighbor(piece, i, j);
		if (piece[i][j] == '\n')
		{
			i++;
			j = 0;
		}
		j++;
	}
	if (k == 6 || k == 8)
		return (1);
}

int			main(int argc, char **argv)
{
		char buff[22];
		int	fd;

		fd = open(argv[1], O_RDONLY);
		read(fd, buff, 21);
		
}
