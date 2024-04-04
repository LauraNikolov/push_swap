/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:46:47 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:36:28 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_sa(t_list **a)
{
	t_list	*tmp;

	if ((*a)->next == NULL || *a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp2 = *b;
	*b = (*b)->next;
	tmp2->next = (*b)->next;
	(*b)->next = tmp2;
	write(1, "ss\n", 3);
}

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}
