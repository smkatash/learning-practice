/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:52:41 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:52:43 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: ft_list_size, ft_list_at
ft list_reverse ; reverse the linked list.
*/

static void		ft_swap(t_list **elem1, t_list **elem2)
{
	void	*tmp_data;

	tmp_data = (*elem1)->data;
	(*elem1)->data = (*elem2)->data;
	(*elem2)->data = tmp_data;
}
void	ft_list_reverse(t_list **begin_list)
{
	t_list			*head;
	t_list			*last;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	size = ft_list_size(*begin_list);
	i = 0;
	j = size - 1;
	while (i < j && i != size / 2)
	{
		head = ft_list_at(*begin_list, i);
		last = ft_list_at(*begin_list, j);
		ft_swap(&head, &last);
		i++;
		j--;
	}
}
