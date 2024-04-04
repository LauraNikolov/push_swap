/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:22:11 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:37:30 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_ra_sa(t_list **list)
{
	ft_ra(list);
	ft_sa(list);
}

void	ft_rra_sa(t_list **list)
{
	ft_rra(list);
	ft_sa(list);
}

int	little_sort(t_list **list)
{
	if (ft_lst_size(list) == 2)
		return (two_sort(list), 0);
	if ((*list)->content < (*list)->next->content
		&& (*list)->next->content < (*list)->next->next->content)
		return (0);
	else if ((*list)->content < (*list)->next->content
		&& (*list)->next->content > (*list)->next->next->content
		&& (*list)->next->next->content > (*list)->content)
		ft_rra_sa(list);
	else if ((*list)->content > (*list)->next->content
		&& (*list)->next->content < (*list)->next->next->content
		&& (*list)->content < (*list)->next->next->content)
		ft_sa(list);
	else if ((*list)->content < (*list)->next->content
		&& (*list)->next->content > (*list)->next->next->content
		&& (*list)->next->next->content < (*list)->content)
		ft_rra(list);
	else if ((*list)->content > (*list)->next->content
		&& (*list)->next->content < (*list)->next->next->content
		&& (*list)->content > (*list)->next->next->content)
		ft_ra(list);
	else if ((*list)->content > (*list)->next->content
		&& (*list)->next->content > (*list)->next->next->content)
		return (ft_ra_sa(list), 0);
	return (0);
}

int	two_sort(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (tmp->content > tmp->next->content)
		ft_sa(list);
	return (0);
}

// void	ft_print_list(t_list *lst)
// {
// 	t_list	*head;

// 	head = lst;
// 	while (lst)
// 	{
// 		printf("%d\n", lst->content);
// 		lst = lst->next;
// 	}
// 	lst = head;
// }
