/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:56:45 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:56:54 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: ft_list_push_front, ft_list_size, ft_list_sort
ft sorted_list_insert ; inserts an element to the linked list
all while keeping the linked list sorted.
*/
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp_int)())
{
	ft_list_push_back(begin_list, data);
	ft_list_sort(begin_list, cmp_int);
}
