/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:44:37 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:36:38 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_rb(t_list **b)
{
	t_list	*first;
	t_list	*last;

	first = *b;
	last = ft_lstlast(*b);
	*b = (*b)->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*last;
	t_list	*firstb;
	t_list	*lastb;

	first = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = first;
	first->next = NULL;
	firstb = *b;
	lastb = ft_lstlast(*b);
	*b = (*b)->next;
	lastb->next = firstb;
	firstb->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **a)
{
	t_list	*second_to_last;
	t_list	*first;
	t_list	*last;

	first = *a;
	last = ft_lstlast(*a);
	second_to_last = ft_second_to_last(*a);
	second_to_last->next = NULL;
	(*a) = last;
	last->next = first;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **b)
{
	t_list	*second_to_last;
	t_list	*first;
	t_list	*last;

	first = *b;
	last = ft_lstlast(*b);
	second_to_last = ft_second_to_last(*b);
	second_to_last->next = NULL;
	(*b) = last;
	last->next = first;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	t_list	*second_to_last;
	t_list	*first;
	t_list	*last;
	t_list	*second_to_lastb;

	first = *a;
	last = ft_lstlast(*a);
	second_to_last = ft_second_to_last(*a);
	second_to_last->next = NULL;
	(*a) = last;
	last->next = first;
	first = *b;
	last = ft_lstlast(*b);
	second_to_lastb = ft_second_to_last(*b);
	second_to_lastb->next = NULL;
	(*b) = last;
	last->next = first;
	write(1, "rrr\n", 4);
}
