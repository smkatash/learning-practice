/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:53:45 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:33:18 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static int		ft_next_prime(int num);
static void	ft_init_items(t_hashtable **htable);

/* Creates struct of hashtable, handles malloc errors,
initializes hashtable params, size (next prime number of a user input)
and items (buckets) with key/value pairs.
*/
t_hashtable	*hashtable_init(void)
{
	unsigned int	size;
	unsigned int	count;
	t_hashtable		*htable;

	if (TABLE_SIZE < 1)
		return (NULL);
	htable = malloc(sizeof(t_hashtable));
	if(!htable)
		return (NULL);
	size = (unsigned int)ft_next_prime(TABLE_SIZE);
	htable->items = (t_hash_item **)malloc(sizeof(t_hash_item *) * size);
	if (!htable->items)
	{
		free(table);
		return (NULL);
	}
	htable->size = size;
	htable->count = 0;
	ft_init_items(&htable);
	return (htable);
}

/* Initializes hash_items (buckets) to NULL */
static void	ft_init_items(t_hashtable **htable)
{
	int i = -1;

	while (++i < size)
		(*htable->items}[i] = NULL;
}

/* Check if number is prime */
static int	is_prime(int num)
{
	int	i = 0;
	int	counter = 0;
	while (i++ <= num)
	{
		if (num % i == 0)
			counter++;
	}
	if (counter != 2)
		return (0);
	else
		return (1);
}

/* If integer is prime, increments it and
verifies non-primes in a loop until prime is found 
*/
static int	ft_next_prime(int num)
{
	if (is_prime(num))
		num++;
	while(!is_prime(num))
		num++;
	return (num);
}
