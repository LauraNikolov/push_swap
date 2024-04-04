/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:12:14 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:36:45 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_ra(t_list **a)
{
	t_list	*first;
	t_list	*last;

	first = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}
