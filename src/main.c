/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:47:28 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:37:03 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_free_tab(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	ft_parse(av, ac, &a);
	ft_arg_is_ok(a);
	ft_push_swap(&a, &b);
	ft_free_tab(a);
	ft_free_tab(b);
}

void	ft_push_swap(t_list **a, t_list **b)
{
	if (ft_lst_size(a) == 2)
	{
		two_sort(a);
		return ;
	}
	if (ft_lst_size(a) == 3)
	{
		little_sort(a);
		return ;
	}
	ft_pb(a, b);
	ft_pb(a, b);
	ft_first_part(a, b);
	ft_second_part(a, b);
}
