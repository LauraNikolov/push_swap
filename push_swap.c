
#include "test.h"


int little_sort(t_list **nods, t_list **list)
{
    t_list *tmp;
    t_list *head;

    head = *list;
    if(ft_lst_size(list) == 2)
    {
        //si le 1er element de la liste est plus grand que le 2e element 
        if((*list)->content == (*nods)->content)
            return(0);
        //si le 1er element de la liste est plus petit que le 2e element
        else 
            return(1);
    }
    return(-1);
}

int ft_rotate_to_top(t_list **nods, t_list **list)
{
    int median;
    int position;
    int cost;
    t_list *temp;
    
    temp = *nods;
    cost = 0;
    median = ft_lst_size((list)) / 2;
    if(ft_lst_size(list) <= 2)
        return(little_sort(nods, list));
    position = ft_find_position(*list, temp->content);
    if(position < median)
        while(position-- > 1 && position < median)
            cost++;
    else if (position > median)
        while(position >= median && position <= ft_lst_size(list))
        {
            cost++;
            position++;
        }
    else if(position == median)
           while(position-- > 1)
            cost++;
  return(cost);
}



void ft_print_list(t_list *lst)
{
    t_list *head;
    head = lst;
    while(lst)
    {
        printf("%d\n", lst->content);
        lst = lst->next;
    }
    lst = head;
}

t_list  *find_target(t_list **a, t_list **b)
{
    t_list *save_b;
    t_list *target;

    save_b = *b;
    target = ft_lstnew(0);
    while(save_b)
    {
        if(it_is_the_biggest(a, b))
        {
            target = ft_biggest(b);
            break;
        }
        if(it_is_the_smallest(a, b))
        {
            target = ft_biggest(b);
            break;
        }
        //si mon nombre b est plus petit au mon nombre A ET que mon nombre b est plus grand que ma target;(target au debut a zero pour le premier tour de boucle)
        if((save_b->content < (*a)->content) && (save_b->content > target->content)) 
            target = save_b;
        save_b = save_b->next;
    }
    return(target);
}



void	ft_push_swap(t_list **a, t_list **b)
{
    /* t_list *best_nods;
    t_list *a_head;
    t_list *tmp;
    int best_cost;

    a_head = *a;
    tmp = *a;
    best_cost = (*a)->cost;
    best_nods = ft_lstnew((*a)->content);
    printf("mon best nods est : %d\n", best_nods->content);
    while(tmp && ft_lst_size(a) > 3)
    {
        ft_init(a, b);
        while(*a)
        {
            if((*a)->cost < best_cost)
            {
                best_cost = (*a)->cost;
                best_nods = *a;
            }
            (*a) = (*a)->next;
        }
    printf("mon best nods est : %d\n", best_nods->content);
    (*a) = a_head;
    ft_push(&best_nods, a, b);
    (*a) = a_head;
    tmp = tmp->next; */

    t_list *save_a;
    ft_init(a, b);
    save_a = *a;
    while(*a)
    {
        printf("target = %d\n", (*a)->target->content);
        printf("content = %d\n", (*a)->content);
        printf("cost = %d\n", (*a)->cost);
        printf("position = %d\n\n", (*a)->position);
        (*a) = (*a)->next;
    }
}   

    
