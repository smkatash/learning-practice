/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:47:03 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:47:19 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: malloc, <stdlib.h>
ft_create_elem : creates a new list element & assigns 'data' to the given argument and 'next' to NULL.
*/

t_list	*ft_create_element(void *data)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if(!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
