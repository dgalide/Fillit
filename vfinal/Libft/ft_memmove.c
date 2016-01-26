/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:35:06 by dgalide           #+#    #+#             */
/*   Updated: 2015/11/30 16:56:51 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * len);
	ft_memcpy((char *)tmp, src, len);
	ft_memcpy(dst, (char *)tmp, len);
	return (dst);
}
