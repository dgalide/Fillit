/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:26:06 by dgalide           #+#    #+#             */
/*   Updated: 2015/11/30 19:24:17 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int i;

	i = 0;
	if (ft_isdigit(c) != i || ft_isalpha(c) != i)
		i = 1;
	return (i);
}
