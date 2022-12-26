/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:57:16 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:57:27 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: ft_list_push_front, ft_list_size, ft_list_sort
ft sorted_list_merge ; merges two linked lists and then sorts the
complete linked list.
*/
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp_int)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
