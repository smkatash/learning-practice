/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:51:17 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:51:31 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/*
DEPENDENCIES: free, <stdlib.h>
ft list_clear ; frees the entire linked list.
*/
void	ft_list_clear(t_list **begin_list)
{
	t_list	*temp;

	if (!begin_list || !(*begin_list))
		return ;
	while(*begin_list)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	*begin_list = NULL;
}
