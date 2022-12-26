/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:54:10 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:36:06 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define TABLE_SIZE 256

# define MIN_LOAD_FACTOR 0.0
# define MAX_LOAD_FACTOR 0.8

# define HTAB_MULTIPLIER 2
# define HTAB_DIVISER 2

// Define the Hash Table Item
typedef struct s_hash_item
{
	char				*key;
	void				*value;
	struct s_hash_item	*next;
}	t_hash_item;

// Define the Hash Table here
typedef struct s_hashtable
{
	unsigned int	size;
	unsigned int	count;
	t_hash_item		*items;
}	t_hashtable ;

t_hashtable	*hashtab_create(unsigned int size);
t_hashtable	*hashtable_init(void);

# endif