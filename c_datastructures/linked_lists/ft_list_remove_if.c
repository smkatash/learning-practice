/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:55:08 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:55:20 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: free, <stdlib.h>
ft list_remove_if ; deletes an element of the linked list if the element's
item matches the item (data_ref) passed as argument.
*/
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *prev;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		if (cmp(data_ref, current->data) == 0)
		{
			if (prev == NULL)
				*begin_list = current->next;
			else
				prev->next = current->next;
			free(current);
		}
		prev = current;
		current = current->next;
	}
}
