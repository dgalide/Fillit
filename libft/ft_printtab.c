/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:55:25 by dgalide           #+#    #+#             */
/*   Updated: 2015/12/07 18:35:14 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printtab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr((char *)tab[i]);
		ft_putchar('\n');
		i++;
	}
}
