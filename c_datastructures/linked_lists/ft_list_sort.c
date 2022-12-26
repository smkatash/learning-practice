/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:56:15 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:56:26 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: ft_list_size
ft list_sort ; sorts the given linked list according to the
'cmp' function.
*/
int	cmp_int(int a, int b)
{
	if (a < b)
		return (0);
	else
		return (1);
}
void	ft_list_sort(t_list **begin_list, int (*cmp_int)())
{
	t_list	*lst1;
	t_list	*lst2;
	void	*tmp_data;

	lst1 = *begin_list;
	while (lst1)
	{
		lst2 = lst1->next;
		while (lst2)
		{
			if ((*cmp_int)(*(int*)lst1->data, *(int*)lst2->data) == 1)
			{
				tmp_data = lst1->data;
				lst1->data = lst2->data;
				lst2->data = tmp_data;
			}
			lst2 = lst2->next;
		}
		lst1 = lst1->next;
	}
}
