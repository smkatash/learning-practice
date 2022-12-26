/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:48:28 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:48:46 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: ft_create_elem
ft_list_push_back ; pushes an element to the back of the list if the list
already exists; else creates an elements and returns an address to it.
*/
void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *temp;

	if (begin_list && (*begin_list))
	{
		temp = (*begin_list);
		while (temp->next)
			temp = temp->next;
		temp->next = ft_create_element(data);
	}
	else
	{
		(*begin_list) = ft_create_element(data);
	}
}
