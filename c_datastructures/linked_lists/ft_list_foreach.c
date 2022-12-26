/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:53:13 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:53:28 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: none.
ft list_foreach ; applys the function 'f' to every element of the
linked list.
*/
static void	f(void *data)
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

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *temp;

	temp = begin_list;
	while(temp)
	{
		(*f)(temp->data);
		temp = temp->next;
	}
}
