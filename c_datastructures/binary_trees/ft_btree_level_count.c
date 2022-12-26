/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:47:01 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/15 00:45:48 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/btree.h"
/*
DEPENDENCIES: None.

int	ft_btree_level_count(t_btree *root):
Recursively visits the left and right side of a node in the tree.
Each node if next left/right node is node not found returns +1 for root.
Previous node receives from its nodes, left = 1 or right = 1,
adds + 1 to the left or right and returns the node that countains 
the biggest amount of nodes/levels incl. itself.
Returns +2 to the previous node, continues until the root receives 
final count of levels.
*/
int	ft_btree_level_count(t_btree *root)
{
	int	left;
	int	right;
	int	rtn;

	if (!root)
		return (0);
	left = 0;
	right = 0;
	if (root->left)
		left = ft_btree_level_count(root->left);
	if (root->right)
		right = ft_btree_level_count(root->right);
	if (left > right)
		rtn = left + 1;
	else
		rtn = right + 1;
	return (rtn);
}

// int	main(void)
// {
// 	t_btree *root;
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
// 	int		zero = 0;
// 	int		t_five = 25;
// 	int		fifty = 50;
// 	int		levels;
// 	int		nodes;

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
// 	levels = ft_btree_level_count(root);
// 	printf("Levels: %d\n", levels);
// }