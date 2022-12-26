/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_btree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:38:14 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/15 00:46:01 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/btree.h"

/*
DEPENDENCIES: None.

void	ft_print_btree(t_btree **root):
Recursively visits nodes on the right side of the tree and adding up spaces by 10.
Prints the content of the nodes separating each node by a new line and adding empty spaces.
Recursively visits and prints the content of nodes on the left side of the tree.

*/
void	ft_print_recurs(t_btree **root, int space)
{
	t_btree	*temp;
	int		i;

	if (root == NULL)
		return ;
	temp = *root;
	space += 10;
	if (temp->right)
		ft_print_recurs(&(temp->right), space);
	printf("\n");
	i = 10;
	while (i < space)
	{
		printf(" ");
		i++;
	}
	printf("( %d )", *(int *)temp->data);
	if (temp->left)
		ft_print_recurs(&(temp->left), space);
}

void	ft_print_btree(t_btree **root)
{
	ft_print_recurs(root, 0);
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
// 	int		twenty= 20;
// 	int		eight= 8;

// 	root = ft_create_new_node((void *)&five);
// 	root->left = ft_create_new_node((void *)&two);
// 	root->left->right = ft_create_new_node((void *)&two);
// 	root->left->left = ft_create_new_node((void *)&one);
// 	root->right = ft_create_new_node((void *)&nine);
// 	root->right->left = ft_create_new_node((void *)&seven);
// 	root->right->left->right = ft_create_new_node((void *)&eight);
// 	root->right->right = ft_create_new_node((void *)&ten);
// 	root->right->right->right = ft_create_new_node((void *)&twenty);
// 	ft_print_btree(&root, 0);
// 	printf("\n");

// }