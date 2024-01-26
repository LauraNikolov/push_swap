/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:09 by lnicolof          #+#    #+#             */
/*   Updated: 2024/01/26 14:25:29 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/* void ft_push(t_list *nods, t_list **list)
{
     
} */

 int  ft_cost(t_list *nods, t_list **a, t_list **b)
{
     int cost_a;
     int cost_b;
     int push;
     int total_push;

     push = 1;
     cost_a = ft_rotate_to_top(&nods, a);
     cost_b = ft_rotate_to_top(&(nods->target), b);
     total_push = cost_a + cost_b + push;
     return (total_push);
}

void   ft_init(t_list **a, t_list **b)
{
    t_list *temp_a;
    t_list *nods;
    t_list **head_a;
    
     temp_a = *a;
    
    while(*a)
   {
        (*a)->target = find_target(a, b);
        (*a)->cost = ft_cost(*a, &temp_a, b);
        (*a)->position = ft_find_position(temp_a, (*a)->content);
        (*a) = (*a)->next;
   } 
   (*a) = temp_a;
}


void ft_init_b(t_list **a, t_list **b)
{
     t_list *temp_b;
     t_list *nods;
     t_list **head_b;

     temp_b = *b;
     while(*b)
     {
         (*b)->target = find_target(b, a);
         (*b)->position = ft_find_position(temp_b, (*b)->content);
         (*b) = (*b)->next;
     }
     (*b) = temp_b;
}

