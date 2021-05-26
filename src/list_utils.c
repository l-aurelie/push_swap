/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:52:18 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 12:15:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_create_elem(void *data)
{
	t_dlist	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->data = data;
	list->e_type = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	ft_dlstadd_front(t_dlist **alst, t_dlist *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_dlstadd_back(t_dlist **alst, t_dlist *new)
{
	t_dlist	*last;
	t_dlist	*begin;

	if (*alst)
	{
		begin = *alst;
		while (begin)
		{
			last = begin;
			begin = begin->next;
		}
		last->next = new;
		new->next = NULL;
	}
	else
		*alst = new;
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_list_push_back(t_dlist **begin_list, void *data)
{
	t_dlist	*current;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = ft_create_elem(data);
	current->next->prev = current;
}
