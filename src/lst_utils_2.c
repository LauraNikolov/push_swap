/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:40:35 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:36:51 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return (NULL);
	if (!*lst)
	{
		*lst = new;
		return (NULL);
	}
	last = ft_lstlast(*lst);
	last->next = new;
	return (NULL);
}

t_list	*ft_lstnew(long content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->content = content;
	rtn->target = NULL;
	rtn->cost = 0;
	rtn->position = 0;
	return (rtn);
}

t_list	*ft_second_to_last(t_list *a)
{
	while (a->next->next != NULL)
		a = a->next;
	return (a);
}

int	ft_find_position(t_list *list, int num)
{
	t_list	*save;
	int		position;

	save = list;
	position = 1;
	while (list)
	{
		if (list->content == num)
			return (position);
		list = list->next;
		position++;
	}
	list = save;
	return (-1);
}
