/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:54:18 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:54:34 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: none.
ft list_find ; finds and returns an address to the first linked list element
that has an item that matches the item (data_ref) passed as argument.
*/

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;

	temp = begin_list;
	while (temp)
	{
		if (cmp(data_ref, temp->data) == 0)
			return (temp);
		else
			temp = temp->next;
	}
	return (NULL);
}