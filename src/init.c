/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:09 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:36:22 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_optimized_cost(t_list **nods, t_list **a, t_list **b)
{
	int	mediane_a;
	int	mediane_b;
	int	cost;

	mediane_a = ft_lst_size(a) / 2;
	mediane_b = ft_lst_size(b) / 2;
	if ((*nods)->target->position == 0)
		(*nods)->target->position = ft_find_position(*b,
				(*nods)->target->content);
	if ((*nods)->target->position > mediane_b && (*nods)->position > mediane_a)
		cost = ft_optimized_rr_cost(nods, a, b);
	else if ((*nods)->target->position <= mediane_b
		&& (*nods)->position <= mediane_a)
	{
		cost = ft_optimized_r_cost(nods, a, b);
	}
	else
		cost = ft_cost(*nods, a, b);
	return (cost);
}

int	ft_cost(t_list *nods, t_list **a, t_list **b)
{
	int	cost_a;
	int	cost_b;
	int	push;
	int	total_push;

	push = 1;
	cost_a = ft_rotate_to_top(&nods, a);
	cost_b = ft_rotate_to_top(&(nods->target), b);
	total_push = cost_a + cost_b + push;
	return (total_push);
}

void	ft_init(t_list **a, t_list **b)
{
	t_list	*temp_a;

	temp_a = *a;
	while (*a)
	{
		(*a)->target = find_target(a, b);
		(*a)->position = ft_find_position(temp_a, (*a)->content);
		(*a)->target->position = ft_find_position(*b, (*a)->target->content);
		(*a)->cost = ft_optimized_cost(a, &temp_a, b);
		(*a) = (*a)->next;
	}
	(*a) = temp_a;
}

void	ft_init_b(t_list **a, t_list **b)
{
	t_list	*temp_b;

	temp_b = *b;
	while (*b)
	{
		(*b)->target = find_target_a(a, b);
		(*b)->position = ft_find_position(temp_b, (*b)->content);
		(*b) = (*b)->next;
	}
	(*b) = temp_b;
}
