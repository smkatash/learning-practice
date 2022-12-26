/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_getcontent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:58:46 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/15 00:45:29 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/btree.h"

int	cmp_match(void *a, void *b)
{
	if (*(int *)a == *(int *)b)
		return (0);
	else
		return (1);
}

/* 
DEPENDENCIES: int	cmp_match(void *a, void *b)

void	*ft_btree_getcontent(t_btree *root, void *data_ref, \
	int (*cmp_match)(void *, void *)):
Recursuively searches for cmp_match == 0 , if found returns 
the content of the node.
*/
void	*ft_btree_getcontent(t_btree *root, void *data_ref, \
	int (*cmp_match)(void *, void *))
{
	if (root)
	{
		if ((*cmp_match)(data_ref, root->data) == 0)
			return (root->data);
		if (root->left)
			return (ft_btree_getcontent(root->left, data_ref, cmp_match));
		if (root->right)
			return (ft_btree_getcontent(root->right, data_ref, cmp_match));
	}
	return (NULL);
}

// int	main(void)
// {
// 	t_btree	*root;
// 	int		one = 1;
// 	int		two = 2;
// 	int		five = 5;
// 	int		nine = 9;
// 	int		ten = 10;
// 	int		seven = 7;
// 	int		twenty = 20;
// 	int		eight = 8;
// 	int		six = 6;
// 	int		four = 4;
// 	int		four_find = 4;
// 	int		zero = 0;
// 	int		t_five = 25;
// 	int		fifty = 50;
// 	void	*content;

// 	root = ft_create_new_node((void *)&five);
// 	ft_btree_insert(&root, (void *)&two, cmpf);
// 	ft_btree_insert(&root, (void *)&nine, cmpf);
// 	ft_btree_insert(&root, (void *)&twenty, cmpf);
// 	ft_btree_insert(&root, (void *)&one, cmpf);
// 	ft_btree_insert(&root, (void *)&five, cmpf);
// 	ft_btree_insert(&root, (void *)&seven, cmpf);
// 	ft_btree_insert(&root, (void *)&eight, cmpf);
// 	ft_btree_insert(&root, (void *)&six, cmpf);
// 	ft_btree_insert(&root, (void *)&four, cmpf);
// 	ft_btree_insert(&root, (void *)&zero, cmpf);
// 	ft_btree_insert(&root, (void *)&one, cmpf);
// 	ft_btree_insert(&root, (void *)&ten, cmpf);
// 	ft_btree_insert(&root, (void *)&t_five, cmpf);
// 	ft_btree_insert(&root, (void *)&fifty, cmpf);
// 	ft_btree_insert(&root, (void *)&five, cmpf);
// 	ft_btree_insert(&root, (void *)&five, cmpf);
// 	ft_print_btree(&root);
// 	printf("\n----------------------\n");
// 	content = ft_btree_getcontent(root, (void *)&one, cmp_match);
// 	printf("Found: %d\n",*(int *)content);
// 	return (0);
// }
