/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:19:08 by lnicolof          #+#    #+#             */
/*   Updated: 2024/01/22 17:49:39 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void ft_push(t_list **nods, t_list **b, t_list **a)
{
    ft_rotate_to_top_push_a(nods, a);
    ft_rotate_to_top_push_b((&(*nods)->target), b);
    ft_pa(a, b);
}

void ft_rotate_to_top_push_a(t_list **nods, t_list **list)
{
    int median;
    int position;
    t_list *temp;
    
    temp = *nods;
    median = ft_lst_size((list)) / 2;
    position = ft_find_position(*list, temp->content);
    if(position < median)
        while(position-- > 1 && position < median)
            ft_ra(list);
    else if (position > median)
        while(position >= median && position <= ft_lst_size(list))
        {
            ft_rra(list);
            position++;
        }
    else if(position == median)
           while(position-- > 1)
            ft_ra(list);
}
void ft_rotate_to_top_push_b(t_list **nods, t_list **list)
{
    int median;
    int position;
    t_list *temp;
    
    temp = *nods;
    median = ft_lst_size((list)) / 2;
    position = ft_find_position(*list, temp->content);
    if(position < median)
        while(position-- > 1 && position < median)
            ft_rb(list);
    else if (position > median)
        while(position >= median && position <= ft_lst_size(list))
        {
            ft_rb(list);
            position++;
        }
    else if(position == median)
           while(position-- > 1)
            ft_rb(list);
}
