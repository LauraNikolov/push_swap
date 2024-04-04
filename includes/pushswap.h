/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:42:55 by lnicolof          #+#    #+#             */
/*   Updated: 2024/02/27 10:26:17 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				cost;
	int				position;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;

void				ft_optimized_rr(t_list **nods, t_list **a, t_list **b);
void				ft_optimized_r(t_list **nods, t_list **a, t_list **b);
int					ft_optimized_rr_cost(t_list **nods, t_list **a, t_list **b);
int					ft_optimized_r_cost(t_list **nods, t_list **a, t_list **b);
void				ft_optimized_push(t_list **nods, t_list **a, t_list **b);
int					ft_optimized_cost(t_list **nods, t_list **a, t_list **b);
void				ft_first_part(t_list **a, t_list **b);
void				ft_second_part(t_list **a, t_list **b);
void				ft_init(t_list **a, t_list **b);
int					little_sort(t_list **list);
int					ft_cost(t_list *nods, t_list **a, t_list **b);
void				ft_init_b(t_list **a, t_list **b);
t_list				**ft_parse(char **nbr, int arg, t_list **a);
int					ft_arg_is_ok(t_list *a);
int					is_it_already_sorted(t_list *a);
void				ft_many_arg(char **nbr, int arg, t_list **a);
int					is_it_nbr(char *str);
void				ft_one_arg(char **nbr, t_list **a);
int					ft_strtablen(char **strs);
char				**ft_split(char const *s, char c);
long				ft_atol(const char *s, t_list **a);
char				**ft_freestrs(char **strs, size_t words);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lst_add_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(long content);
t_list				*ft_second_to_last(t_list *a);
int					it_is_the_biggest(t_list **a, t_list **b);
int					it_is_the_smallest(t_list **a, t_list **b);
t_list				*ft_biggest(t_list **list);
t_list				*ft_smaller(t_list **list);
int					ft_lst_size(t_list **lst);
int					ft_find_position(t_list *lst, int num);
void				ft_print_list(t_list *lst);
void				ft_free_tab(t_list *a);
void				ft_error(void);
void				ft_sa(t_list **a);
void				ft_sb(t_list **b);
void				ft_ss(t_list **a, t_list **b);
void				ft_pa(t_list **a, t_list **b);
void				ft_pb(t_list **a, t_list **b);
void				ft_ra(t_list **a);
void				ft_rb(t_list **b);
void				ft_rr(t_list **a, t_list **b);
void				ft_rra(t_list **a);
void				ft_rrb(t_list **b);
void				ft_rrr(t_list **a, t_list **b);
void				ft_push_swap(t_list **a, t_list **b);
int					ft_rotate_to_top(t_list **nods, t_list **list);
void				ft_rotate_to_top_a(t_list **nods, t_list **list);
void				ft_rotate_to_top_b(t_list **nods, t_list **list);
void				ft_rotate_to_top_push_a(t_list **nods, t_list **list);
void				ft_rotate_to_top_push_b(t_list **nods, t_list **list);
t_list				*find_target(t_list **a, t_list **b);
t_list				*find_target_a(t_list **a, t_list **b);
int					two_sort(t_list **list);
void				ft_ra_sa(t_list **list);
void				ft_rra_sa(t_list **list);

#endif