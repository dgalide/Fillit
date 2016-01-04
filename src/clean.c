/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:46:05 by jtranchi          #+#    #+#             */
/*   Updated: 2015/12/15 17:46:10 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void		ft_del_first_line(t_piece *piece)
{
	int y;
	int x;

	y = 0;
	while (++y < piece->y_size)
	{
		x = -1;
		while (++x < piece->x_size)
			piece->content[y - 1][x] = piece->content[y][x];
	}
}

void		ft_del_first_col(t_piece *piece)
{
	int y;
	int x;

	x = 0;
	while (++x < piece->x_size)
	{
		y = -1;
		while (++y < piece->y_size)
			piece->content[y][x - 1] = piece->content[y][x];
	}
}

void		ft_yclean(t_piece *piece)
{
	int x;
	int y;
	int test;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		test = 1;
		while (++x < 4)
			if (piece->content[y][x] == '#')
				test = 0;
		if (test)
		{
			if (y == 0)
			{
				ft_del_first_line(piece);
				y = -1;
			}
			piece->y_size--;
		}
	}
}

void		ft_xclean(t_piece *piece)
{
	int x;
	int y;
	int test;

	test = 1;
	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (piece->content[y][x] == '#')
				test = 0;
		if (test)
		{
			if (x == 0)
			{
				ft_del_first_col(piece);
				x = -1;
			}
			piece->x_size--;
		}
		test = 1;
	}
}

void		ft_count(t_piece *piece)
{
	int x;
	int y;
	int count;

	count = 0;
	y = -1;
	while (++y < piece->y_size)
	{
		x = -1;
		while (++x < piece->x_size)
			if (piece->content[y][x] == '#')
				count++;
	}
	if (count != 4)
		ft_error();
}
