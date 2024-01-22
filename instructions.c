
#include "test.h"

/* sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun. */
void	ft_sa(t_list **a)
{
	t_list	*tmp;

	if ((*a)->next == NULL || *a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}
/* sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun. */
void	ft_sb(t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}
/* ss : sa et sb en même temps */
void	ft_ss(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp2 = *b;
	*b = (*b)->next;
	tmp2->next = (*b)->next;
	(*b)->next = tmp2;
}
/* pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide */
void	ft_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}
/* 
	    pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide. */
void	ft_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
/* ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier. */
void	ft_ra(t_list **a)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	first = *a;
	last = ft_lstlast(*a);
	*a = (*a)->next;
	last->next = first;
	first->next = NULL;
}

/* rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.*/
void	ft_rb(t_list **b)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	first = *b;
	last = ft_lstlast(*b);
	*b = (*b)->next;
	last->next = first;
	first->next = NULL;
}
/* rr : ra et rb en même temps.*/
void	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a);
	ft_rb(b);
}
/* rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.(=> pour choper l'avant dernier
	->next->next) */
void	ft_rra(t_list **a)
{
	t_list	*second_to_last;
	t_list	*first;
	t_list	*last;

	first = *a;
	last = ft_lstlast(*a);
	second_to_last = ft_second_to_last(*a);
	second_to_last->next = NULL;
	(*a) = last;
	last->next = first;
}
/* rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier. */
void	ft_rrb(t_list **b)
{
	t_list	*second_to_last;
	t_list	*first;
	t_list	*last;

	first = *b;
	last = ft_lstlast(*b);
	second_to_last = ft_second_to_last(*b);
	second_to_last->next = NULL;
	(*b) = last;
	last->next = first;
}
/*rrr : rra et rrb en même temps */
void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a);
	ft_rrb(b);
}