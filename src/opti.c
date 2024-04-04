/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:56:41 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:37:08 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_optimized_r(t_list **nods, t_list **a, t_list **b)
{
	int	cost_a;
	int	cost_b;

	cost_a = ft_rotate_to_top(nods, a);
	cost_b = ft_rotate_to_top((&(*nods)->target), b);
	if (cost_a > cost_b)
	{
		while ((*b)->content != (*nods)->target->content)
			ft_rr(a, b);
		while ((*a)->content != (*nods)->content)
			ft_ra(a);
	}
	else if (cost_b > cost_a)
	{
		while ((*a)->content != (*nods)->content)
			ft_rr(a, b);
		while ((*b)->content != (*nods)->target->content)
			ft_rb(b);
	}
	else if (cost_a == cost_b)
		while ((*b)->content != (*nods)->target->content)
			ft_rr(a, b);
}

void	ft_optimized_rr(t_list **nods, t_list **a, t_list **b)
{
	int	cost_a;
	int	cost_b;

	cost_a = ft_rotate_to_top(nods, a);
	cost_b = ft_rotate_to_top((&(*nods)->target), b);
	if (cost_a > cost_b)
	{
		while ((*b)->content != (*nods)->target->content)
			ft_rrr(a, b);
		while ((*a)->content != (*nods)->content)
			ft_rra(a);
	}
	else if (cost_b > cost_a)
	{
		while ((*a)->content != (*nods)->content)
			ft_rrr(a, b);
		while ((*b)->content != (*nods)->target->content)
			ft_rrb(b);
	}
	else if (cost_a == cost_b)
		while ((*b)->content != (*nods)->target->content)
			ft_rrr(a, b);
}

int	ft_optimized_r_cost(t_list **nods, t_list **a, t_list **b)
{
	int	cost_a;
	int	cost_b;
	int	cost;

	cost = 0;
	cost_a = ft_rotate_to_top(nods, a);
	cost_b = ft_rotate_to_top((&(*nods)->target), b);
	if (cost_a > cost_b)
	{
		cost += cost_b;
		cost += cost_a - cost_b;
	}
	else if (cost_b > cost_a)
	{
		cost += cost_a;
		cost += cost_b - cost_a;
	}
	else
	{
		cost = cost_a;
	}
	return (cost + 1);
}

int	ft_optimized_rr_cost(t_list **nods, t_list **a, t_list **b)
{
	int	cost_a;
	int	cost_b;
	int	cost;

	cost = 0;
	cost_a = ft_rotate_to_top(nods, a);
	cost_b = ft_rotate_to_top((&(*nods)->target), b);
	if (cost_a > cost_b)
	{
		cost += cost_b;
		cost += cost_a - cost_b;
	}
	else if (cost_b > cost_a)
	{
		cost += cost_a;
		cost += cost_b - cost_a;
	}
	else
	{
		cost = cost_a;
	}
	return (cost + 1);
}

void	ft_optimized_push(t_list **nods, t_list **a, t_list **b)
{
	int	mediane_a;
	int	mediane_b;

	mediane_a = ft_lst_size(a) / 2;
	mediane_b = ft_lst_size(b) / 2;
	if ((*nods)->target->position > mediane_b && (*nods)->position > mediane_a)
	{
		ft_optimized_rr(nods, a, b);
	}
	else if ((*nods)->target->position <= mediane_b
		&& (*nods)->position <= mediane_a)
	{
		ft_optimized_r(nods, a, b);
	}
	else
	{
		ft_rotate_to_top_push_a(nods, a);
		ft_rotate_to_top_push_b((&(*nods)->target), b);
	}
}
