/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:07:43 by ktashbae          #+#    #+#             */
/*   Updated: 2022/08/29 11:54:49 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_btree
{
	void			*data;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

t_btree	*ft_create_new_node(void *content);
void	ft_btree_insert(t_btree **root, void *item, \
	int (*cmpf)(void *, void *));
void	ft_print_btree(t_btree **root);
int		ft_btree_node_count(t_btree *root);
int		ft_btree_level_count(t_btree *root);
void	*ft_btree_getcontent(t_btree *root, void *data_ref, \
	int (*cmp_match)(void *, void *));

#endif
