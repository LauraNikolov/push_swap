
#include "test.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return (NULL);
	if (!*lst)
	{
		*lst = new;
		return (NULL);
	}
	last = ft_lstlast(*lst);
	last->next = new;
	return (NULL);
}

t_list	*ft_lstnew(long content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (rtn = NULL);
	rtn->next = NULL;
	rtn->content = content;
  rtn->target = NULL;
  rtn->cost = 0;
  rtn->position = 0;
	return (rtn);
}
t_list	*ft_second_to_last(t_list *a)
{
	while (a->next->next != NULL)
		a = a->next;
	return (a);
}
//retourne vrai si *a est le plus grand eet retourne faux si ce n'est pas le cas
// 1 = true et 0 = false
int it_is_the_biggest(t_list **a, t_list **b)
{
  t_list *tmp;
  int a_content;
  int biggest;

    a_content = (*a)->content;
  tmp = *b;
  while(*b)
  {
    if((*a)->content > (*b)->content)
      biggest = (*a)->content;
    else
    {
        *b = tmp;
        return(0);
    } 
    *b = (*b)->next;
  }
    *b = tmp;
  if(biggest == a_content)
    return(1);
  else
    return(0);  
}
int it_is_the_smallest(t_list **a, t_list **b)
{
  t_list *tmp;
  int a_content;
  int smallest;
  
    a_content = (*a)->content;
    tmp = *b;
  while(*b)
  {
    if((*a)->content < (*b)->content)
      smallest = (*a)->content;
    else
    {
        *b = tmp;
        return(0);
    }
    *b = (*b)->next;
  }
    *b = tmp;
  if(smallest == a_content)
    return(1);
  else
    return(0);  
}

//retourne le noeud le plus grand de la liste
t_list *ft_biggest(t_list **list)
{
    t_list *biggest;
    t_list *temp;
    temp = *list;
    biggest = *list;
    while(*list)
    {
        if((biggest->content < (*list)->content))
            biggest = *list;
        *list = (*list)->next;
    }
    *list = temp;
    return(biggest);
}
//retourne le noeud le plus petit de la liste
t_list *ft_smaller(t_list **list)
{
    t_list *smallest;
    t_list *temp;
    temp = *list;
    smallest = *list;
    while(*list)
    {
        if((smallest->content > (*list)->content))
            smallest = *list;
        *list = (*list)->next;
    }
    *list = temp;
    return(smallest);
}

int ft_lst_size(t_list **lst)
{
	int i;
	t_list *head;
	head = *lst;
	i = 0;
	while(*lst)
	{
		i++;
		*lst = (*lst)->next;
	}
	*lst = head;
	return(i);
}
int ft_find_position(t_list *list, int num)
{
    t_list *save;

    save = list;
    int position = 1;
    while (list)
    {
        if (list->content == num)
            return position;
        list = list->next;
        position++;
    }
    list = save;
    return -1; // Retourne -1 si le nombre n'est pas trouvé
}
