/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:35:13 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/15 00:45:44 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/btree.h"

int	cmpf(void *a, void *b)
{
	if (*(int *)a <= *(int *)b)
		return (-1);
	else
		return (0);
}

/* 
DEPENDENCIES: 
int		cmpf(void *a, void *b)
t_btree	*ft_create_new_node(void *content)

void	ft_btree_insert(t_btree **root, void *item, int (*cmpf)(void *, void *)):
Recursuively goes through the nodes, applies cmpf for comparison, 
if item to insert is bigger then node data, it goes to the right, else to the left.
All data smaller than the node go to the left. All data equal or bigger than the node
go to the right side of the node. If next node is empty, new node with item to insert is created. 
If root is empty, the new created node is set as root.
*/
void	ft_btree_insert(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*temp;

	if (root == NULL || *root == NULL)
	{
		if (root)
			*root = ft_create_new_node(item);
		return ;
	}
	temp = *root;
	if ((*cmpf)(temp->data, item) == -1)
	{
		if (temp->right)
			ft_btree_insert(&(temp->right), item, cmpf);
		else
		{
			temp->right = ft_create_new_node(item);
			return ;
		}
	}
	else
	{
		if (temp->left)
			ft_btree_insert(&(temp->left), item, cmpf);
		else
		{
			temp->left = ft_create_new_node(item);
			return ;
		}
	}
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
// }
