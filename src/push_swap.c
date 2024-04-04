/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:17:15 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:37:14 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_list	*find_target_a(t_list **a, t_list **b)
{
	t_list	*save_a;
	t_list	*target;

	save_a = *a;
	target = ft_biggest(a);
	while (save_a)
	{
		if (it_is_the_biggest(b, a))
		{
			target = ft_smaller(a);
			break ;
		}
		if (it_is_the_smallest(b, a))
		{
			target = ft_smaller(a);
			break ;
		}
		if ((save_a->content > (*b)->content)
			&& (save_a->content < target->content))
			target = save_a;
		save_a = save_a->next;
	}
	return (target);
}

int	ft_rotate_to_top(t_list **nods, t_list **list)
{
	int		median;
	int		position;
	int		cost;
	t_list	*temp;

	temp = *nods;
	cost = 0;
	median = ft_lst_size((list)) / 2;
	position = ft_find_position(*list, temp->content);
	if (position < median)
		while (position-- > 1 && position < median)
			cost++;
	else if (position > median)
	{
		while (position >= median && position <= ft_lst_size(list))
		{
			cost++;
			position++;
		}
	}
	else if (position == median)
		while (position-- > 1)
			cost++;
	return (cost);
}

t_list	*find_target(t_list **a, t_list **b)
{
	t_list	*save_b;
	t_list	*target;

	save_b = *b;
	target = ft_smaller(b);
	while (save_b)
	{
		if (it_is_the_biggest(a, b))
		{
			target = ft_biggest(b);
			break ;
		}
		if (it_is_the_smallest(a, b))
		{
			target = ft_biggest(b);
			break ;
		}
		if ((save_b->content < (*a)->content)
			&& (save_b->content > target->content))
			target = save_b;
		save_b = save_b->next;
	}
	return (target);
}

void	ft_first_part(t_list **a, t_list **b)
{
	t_list	*save_a;
	t_list	*best_cost;

	best_cost = *a;
	while (ft_lst_size(a) > 3)
	{
		save_a = *a;
		best_cost = *a;
		ft_init(a, b);
		while (save_a)
		{
			if ((save_a->cost < best_cost->cost))
			{
				best_cost = save_a;
			}
			save_a = save_a->next;
		}
		ft_optimized_push(&best_cost, a, b);
		ft_pb(a, b);
	}
	little_sort(a);
}

void	ft_second_part(t_list **a, t_list **b)
{
	t_list	*smaller;

	while (*b)
	{
		ft_init_b(a, b);
		if ((*a)->content != (*b)->target->content)
		{
			ft_rotate_to_top_push_a(&((*b)->target), a);
			ft_pa(a, b);
		}
		else if ((*a)->content == (*b)->target->content)
			ft_pa(a, b);
	}
	smaller = ft_smaller(a);
	if (smaller->content != (*a)->content)
		ft_rotate_to_top_push_a(&smaller, a);
}
