/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:42:27 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:36:57 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	it_is_the_biggest(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		a_content;
	int		biggest;

	a_content = (*a)->content;
	tmp = *b;
	while (*b)
	{
		if ((*a)->content > (*b)->content)
			biggest = (*a)->content;
		else
		{
			*b = tmp;
			return (0);
		}
		*b = (*b)->next;
	}
	*b = tmp;
	if (biggest == a_content)
		return (1);
	else
		return (0);
}

int	it_is_the_smallest(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		a_content;
	int		smallest;

	a_content = (*a)->content;
	tmp = *b;
	while (*b)
	{
		if ((*a)->content < (*b)->content)
			smallest = (*a)->content;
		else
		{
			*b = tmp;
			return (0);
		}
		*b = (*b)->next;
	}
	*b = tmp;
	if (smallest == a_content)
		return (1);
	else
		return (0);
}

t_list	*ft_biggest(t_list **list)
{
	t_list	*biggest;
	t_list	*temp;

	temp = *list;
	biggest = *list;
	while (*list)
	{
		if ((biggest->content < (*list)->content))
			biggest = *list;
		*list = (*list)->next;
	}
	*list = temp;
	return (biggest);
}

t_list	*ft_smaller(t_list **list)
{
	t_list	*smallest;
	t_list	*temp;

	temp = *list;
	smallest = *list;
	while (*list)
	{
		if ((smallest->content > (*list)->content))
			smallest = *list;
		*list = (*list)->next;
	}
	*list = temp;
	return (smallest);
}

int	ft_lst_size(t_list **lst)
{
	int		i;
	t_list	*head;

	head = *lst;
	i = 0;
	while (*lst)
	{
		*lst = (*lst)->next;
		i++;
	}
	*lst = head;
	return (i);
}
