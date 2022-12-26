/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:53:50 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:54:01 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: f(void*), (*cmp)().
ft list_foreach_if ; applys the function 'f' to every element of the
linked list if the item of the linked list element matches the item
(data_ref) passed as argument.
*/

static void	func(void *data)
{
	char	*s;
	int		i;

	s = (char *)data;
	i = 0;
	while (s[i])
	{
		s[i] -= 32;
		i++;
	}
}

static int	cmp(void* a, void *b)
{
	char	*sa;
	char	*sb;
	int		i;
	int		len;

	sa = (char *)a;
	sb = (char *)b;
	i = 0;
	len = 0;
	while(sa[len])
		len++;
	while (sa[i] && sa[i] == sb[i])
		i++;
	if (i == len)
		return (0);
	else
		return (1);
}

void	ft_list_foreach_if(t_list *begin_list, void (*func)(void *), void *data_ref, int (*cmp)())
{
	t_list *temp;

	temp = begin_list;
	while(temp)
	{
		if (cmp(data_ref, temp->data) == 0)
			(*func)(temp->data);
		temp = temp->next;
	}
}
