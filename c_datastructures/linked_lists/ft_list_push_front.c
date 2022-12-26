/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:49:06 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:49:17 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: ft_create_elem
ft list_push_front ; pushes an element to the front of the list if the list
already exists and updates the pointer to the pointer to the head of the list;
else creates an element and returns an address to it.
*/
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_element(data);
	new->next = *begin_list;
	*begin_list = new;
}
