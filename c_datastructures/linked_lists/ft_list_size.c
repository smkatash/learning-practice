/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:49:35 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:49:47 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: none.
ft list_size ; returns the size of the linked list (number of elements).
*/
int	ft_list_size(t_list *begin_list)
{
	t_list	*temp;
	int		len;

	len = 0;
	temp = begin_list;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
