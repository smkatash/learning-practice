/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:58:05 by kanykei           #+#    #+#             */
/*   Updated: 2022/09/15 00:58:08 by kanykei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*temp;
// 	t_list	*tmp;
// 	t_list	*a;
// 	int		i;
// 	int		j;
// 	int		x;
// 	int		y;
// 	int		z;
// 	t_list	h;
// 	t_list	b;
// 	t_list	c;
// 	t_list	d;
// 	t_list	e;
	
	/* _______________________________________*/
	/* t_list	*ft_create_element(void *data) */
	// lst = malloc(sizeof(t_list));
	// lst->data = (char *)"hello";
	// lst->next = NULL;
	// lst = ft_create_element("bye");
	// while (lst)
	// {
	// 	printf("%s \n", (char*)lst->data);
	// 	lst = lst->next;
	// }

	/* _______________________________________*/
	/* void	ft_list_push_back(t_list **begin_list, void *data) */
	// lst = NULL;
	// ft_list_push_back(&lst, "hi");
	// ft_list_push_back(&lst, "world");
	// ft_list_push_back(&lst, "42 is the answer");
	// while (lst)
	// {
	// 	printf("%s \n", (char*)lst->data);
	// 	lst = lst->next;
	// }

	/* _______________________________________*/
	/* void	ft_list_push_front(t_list **begin_list, void *data) */
	// ft_list_push_front(&lst, "new element");
	// ft_list_push_front(&lst, "here is a");
	// while (lst)
	// {
	// 	printf("%s \n", (char*)lst->data);
	// 	lst = lst->next;
	// }
	
	/* _______________________________________*/
	/* int	ft_list_size(t_list *begin_list) */
	// i = ft_list_size(lst);
	// printf("Size: %d ", i);
	
	/* _______________________________________*/
	/* t_list	*ft_list_last(t_list *begin_list) */
	// temp = ft_list_last(lst);
	// printf("%s ", (char*)temp->data);

	/* _______________________________________*/
	/* void	ft_list_clear(t_list **begin_list) */
	// ft_list_clear(&lst);
	// while (lst)
	// {
	// 	printf("%s \n", (char*)lst->data);
	// 	printf("here");
	// 	lst = lst->next;
	// }

	/* _______________________________________ */
	/* t_list	*ft_list_at(t_list *begin_list, unsigned int nbr) */
	// temp = ft_list_at(lst, 3);
	// printf("%s ", (char *)temp->data);

	/* _______________________________________ */
	/* void	ft_list_reverse(t_list **begin_list) */
	// ft_list_reverse(&lst);
	// while (lst)
	// {
	// 	printf("%s \n", (char*)lst->data);
	// 	lst = lst->next;
	// }

	/* void	ft_list_foreach(t_list *begin_list, void (*f)(void *)) */
	// a = malloc(sizeof(t_list));
	// a->data = (void*)strdup("hello");
	// a->next = malloc(sizeof(t_list));
	// a->next->data = (void*)strdup("bye");
	// a->next->next = malloc(sizeof(t_list));
	// a->next->next->data = (void*)strdup("how");
	// a->next->next->next = malloc(sizeof(t_list));
	// a->next->next->next->data = (void*)strdup("are");
	// a->next->next->next->next = malloc(sizeof(t_list));
	// a->next->next->next->next->data = (void*)strdup("you");
	// a->next->next->next->next->next = NULL;
	// ft_list_foreach(a, f);
	// temp = a;
	// while(temp)
	// {
	// 	printf("%s \n", (char*)temp->data);
	// 	temp = temp->next;
	// }
	// tmp = a;
	// while(tmp)
	// {
	// 	free(tmp->data);
	// 	temp = tmp->next;
	// 	free(tmp);
	// 	tmp = temp;
	// }


	/* _______________________________________ */
/* void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)()) */
	// h.data = (void*)strdup("hello");
	// h.next = &b;
	// b.data = (void*)strdup("bye");
	// b.next = &c;
	// c.data = (void*)strdup("how");
	// c.next = &d;
	// d.data = (void*)strdup("are");
	// d.next = &e;
	// e.data = (void*)strdup("you");
	// e.next = NULL;
	// ft_list_foreach_if(&h, func, "are", cmp);
	// temp = &h;
	// while(temp)
	// {
	// 	printf("%s, ", (char*)temp->data);
	// 	temp = temp->next;
	// }


	/* _______________________________________ */
/* t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)()) */
	// temp = ft_list_find(&h, "how", cmp);
	// while(temp)
	// {
	// 	printf("%s, ", (char*)temp->data);
	// 	temp = temp->next;
	// }

	/* _______________________________________ */
/* void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) */
	// ft_list_remove_if(&a, "how", cmp);
	// temp = a;
	// while(temp)
	// {
	// 	printf("%s \n", (char*)temp->data);
	// 	temp = temp->next;
	// }

	/* _______________________________________ */
/* void	ft_list_merge(t_list **begin_list1, t_list *begin_list2) */
	// lst = malloc(sizeof(t_list));
	// lst->data = (void*)strdup("this is list2");
	// lst->next = malloc(sizeof(t_list));
	// lst->next->data = (void*)strdup("the end");
	// lst->next->next = NULL;
	// ft_list_merge(&a, lst);
	// temp = a;
	// while(temp)
	// {
	// 	printf("%s \n", (char*)temp->data);
	// 	temp = temp->next;
	// }

	/* _______________________________________ */
/*	void	ft_list_sort(t_list **begin_list, int (*cmp)()) */
	// i = 200;
	// h.data = &i;
	// h.next = &b;
	// j = 3;
	// b.data = &j;
	// b.next = &c;
	// x = 0;
	// c.data = &x;
	// c.next = &d;
	// y = 6;
	// d.data = &y;
	// d.next = &e;
	// z = -5;
	// e.data = &z;
	// e.next = NULL;
	// temp = &h;
	// ft_list_sort(&temp, cmp_int);
	// while(temp)
	// {
	// 	printf("%d \n", *(int*)temp->data);
	// 	temp = temp->next;
	// }

	/* _______________________________________ */
/*	void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)()); */
/*	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)()); */

	// tmp = a;
	// while(tmp)
	// {
	// 	free(tmp->data);
	// 	temp = tmp->next;
	// 	free(tmp);
	// 	tmp = temp;
	// }
// 	return (0);
// }
