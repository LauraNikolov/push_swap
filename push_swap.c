
#include "test.h"

/* int is_it_ordered(t_list **list)
{
    t_list *head;
     head = *list;

     while(list)
     {
        if((*list)->next->content < (*list)->content)
            return(0);
        *list = (*list)->next;
     }
     *list = head;
        return(1);
} */

/* void    ft_last_push(t_list **a, t_list **b)
{
   if(!is_it_ordered(b))
   {
    printf("PAS ORDONNE\n")
    ft_ordered(b);
   } 
   if(!is_it_ordered(a))
   {
    printf("PAS ORDONNE\n")
    ft_ordered(a);
   }

   ft_init_push_end(a, b);


} */

t_list  *find_target_a(t_list **a, t_list **b)
{
    t_list *save_a;
    t_list *target;

    save_a = *a;
    target = ft_biggest(a);
    while(save_a)
    {
        if(it_is_the_biggest(b, a))
        {
            target = ft_smaller(a);
            //printf("je PASSE ICI et mon content est %d\n", (*b)->content);
            break;
        }
        if(it_is_the_smallest(b, a))
        {
            target = ft_smaller(a);
            //printf("je PASSE ICI 2 et mon content est %d\n et ma target %d", (*b)->content, target->content);
            break;
        }
        //si mon nombre dans a est plus petit que mon nombre dans b et que mon nombre a est plus grand que mon save 
        if((save_a->content > (*b)->content) && (save_a->content < target->content)) 
            target = save_a;
        save_a = save_a->next;
    }
    return(target);
}
int little_sort(t_list **list)
{
    t_list *tmp;

    tmp = *list;
    //1 2 3
    if(tmp->content < tmp->next->content && tmp->next->content < tmp->next->next->content)
        return(0);
    //1 3 2
  else if(tmp->content < tmp->next->content && tmp->next->content > tmp->next->next->content && tmp->next->next->content > tmp->content)
    {
        ft_rra(list);
        ft_sa(list);
    }
    //2 1 3
    else if(tmp->content > tmp->next->content && tmp->next->content < tmp->next->next->content && tmp->content < tmp->next->next->content)
        ft_sa(list);
    //2 3 1
   else if(tmp->content < tmp->next->content && tmp->next->content > tmp->next->next->content && tmp->next->next->content < tmp->content)
    {
        ft_rra(list);
    }
    //3 1 2
    else if(tmp->content > tmp->next->content && tmp->next->content < tmp->next->next->content && tmp->content > tmp->next->next->content)
    {
        ft_ra(list);
    }
    //3 2 1
    else if(tmp->content > tmp->next->content && tmp->next->content > tmp->next->next->content)
    {
        ft_ra(list);
        ft_sa(list);
    }
    return(0);
}

int two_sort(t_list **list)
{
    t_list *tmp;

    tmp = *list;
    if(tmp->content > tmp->next->content)
        ft_sa(list);
    return(0);
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
    /* if(ft_lst_size(list) == 2)
        return(two_sort(list)); */
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
    t_list *save_a;
    t_list *tmp;
    t_list *head;
    t_list *best_cost;
    t_list *save_b;
    t_list *head_b;
    t_list *head_a;
    t_list *test;
    t_list *smaller;

    tmp = *a;
    best_cost = ft_lstnew(0);
    save_b = *b;
    head_b = *b;
    head_a = *a;
    // * MA FONCTION QUI PUSH EN ORDRE DECROISSSANT DANS LA B
    while(ft_lst_size(&tmp) > 3)
    {
        save_a = *a;
        best_cost = *a;
        ft_init(a, b);
        while(save_a)
        {
            if((tmp->cost < best_cost->cost))
                best_cost = tmp;
            save_a = save_a->next;
        }
        tmp = tmp->next;
        ft_rotate_to_top_push_a(&best_cost, a);
        ft_rotate_to_top_push_b(&(best_cost->target), b);
        ft_pb(a, b);
    }
    little_sort(a);
  /*   printf("A\n");
    ft_print_list(*a);
    printf("B\n");
    ft_print_list(*b); 
    int i = 0; */
// * MA FONCTION QUI PUSH EN ORDRE DECROISSSANT DANS LA B
     while(*b)
    {
        ft_init_b(a, b);
        //printf("MA TARGET EST %d\n", (*b)->target->content);
        // Tant que target != position faire les moves necessaire
        if((*a)->content != (*b)->target->content)
        {
            ft_rotate_to_top_push_a(&((*b)->target), a);
            ft_pa(a, b);
        }
        else if ((*a)->content == (*b)->target->content)
            ft_pa(a, b);
       /* printf("A MOVES TOUR NUMERO %d \n", i);
        ft_print_list(*a);
        printf("B MOVES TOUR NUMERO %d \n", i);
        ft_print_list(*b);
        i++; */
    }
    smaller = ft_smaller(a);
   if(smaller->content != (*a)->content)
         ft_rotate_to_top_push_a(&smaller, a);
     printf("A FINAL \n");
    ft_print_list(*a);
    printf("B FINAL\n");
    ft_print_list(*b);
} 



    
