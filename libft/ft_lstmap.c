/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:47:40 by dgalide           #+#    #+#             */
/*   Updated: 2015/12/03 17:07:40 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *cpy;

	cpy = (t_list *)malloc(sizeof(t_list *));
	if (!cpy || !lst)
		return (NULL);
	cpy = f(lst);
	cpy->next = ft_lstmap(lst->next, f);
	return (cpy);
}
