/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hastab_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:42:02 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:42:05 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

/* prerequisites shrink && grow WIP */

int	hashtab_insert(t_hashtable **table, char *key, void *value)
{
	if (table && key && value)
	{
		if ((*table) == NULL)
			*table = hashtab_init();
		if (*table)
		{
			
		}
	}
}

static int	