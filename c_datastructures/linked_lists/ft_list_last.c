/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:50:14 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:50:38 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: none.
ft list_last ; returns the address of to the last element of the
list; else NULL.
*/
t_list	*ft_list_last(t_list *begin_list)
{
	t_list *temp;

	temp = begin_list;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}