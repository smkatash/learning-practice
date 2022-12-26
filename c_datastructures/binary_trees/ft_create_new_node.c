/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:31:03 by ktashbae          #+#    #+#             */
/*   Updated: 2022/09/15 00:45:57 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/btree.h"

/* 
DEPENDENCIES: None.

t_btree	*ft_create_new_node(void *content): 
Creates a new node with initialisation */
t_btree	*ft_create_new_node(void *content)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	node->data = content;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// int	main(void)
// {
// 	t_btree	*parent;
// 	t_btree	*temp;
// 	int		num;
// 	int		num1;
// 	int		num2;
// 	int		num1_2;
// 	int		num2_2;
// 	int		new_num;


	/* t_btree	*create_new_node(void *content) */
	// num = 2;
	// num1 = 1;
	// num2 = 3;
	// num1_2 = 0;
	// num2_2 = 5;
	// parent = create_new_node((void *)&num);
	// parent->left = create_new_node((void *)&num1);
	// parent->left->left = create_new_node((void *)&num1_2);
	// parent->right = create_new_node((void *)&num2);
	// parent->right->right = create_new_node((void *)&num2_2);
	// temp = parent;
	// if (parent)
	// {
	// 	printf("Data parent: %d\n", *(int *)temp->data);
	// 	if (temp->left)
	// 	{
	// 		while (temp->left)
	// 		{
	// 			printf("Data left: %d\n", *(int *)temp->left->data);
	// 			temp = temp->left;
	// 		}
	// 	}
	// 	temp = parent;
	// 	if (temp->right)
	// 	{
	// 		while (temp->right)
	// 		{
	// 			printf("Data right: %d\n", *(int *)temp->right->data);
	// 			temp = temp->right;
	// 		}
	// 	}
	// }
//}
