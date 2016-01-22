/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:48:05 by mchevall          #+#    #+#             */
/*   Updated: 2016/01/19 17:36:19 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		range_min(int nb_tetri)
{
	int		i;

	i = 0;
	while (i * i < nb_tetri * 4)
		i++;
	return(i);
}
