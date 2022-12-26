/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:55:42 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:55:54 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: ft_list_last
ft list_merge ; appends (merges) linked list #2 to the end of linked
list #1.
*/
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *last;

	if (!begin_list1 || !(*begin_list1))
		*begin_list1 = begin_list2;
	else
	{
		last = ft_list_last(*begin_list1);
		last->next = begin_list2;
	}
}
