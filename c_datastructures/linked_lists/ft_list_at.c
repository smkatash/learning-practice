/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:51:59 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:52:07 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: none.
ft list_at ; returns an address to the N'th element (nbr being N).
*/
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*temp;
	int		i;

	i = 1;
	if (!begin_list)
		return (NULL);
	while (i < nbr && begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (begin_list);
}
