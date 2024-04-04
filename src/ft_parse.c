/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:04:56 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:36:09 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_one_arg(char **nbr, t_list **a)
{
	int			i;
	int long	content;
	char		**strs;

	i = 0;
	strs = ft_split(nbr[1], ' ');
	while (strs[i])
	{
		if (is_it_nbr(strs[i]))
		{
			content = ft_atol(strs[i++], a);
			ft_lst_add_back(a, ft_lstnew(content));
		}
		else
		{
			ft_free_tab(*a);
			ft_freestrs(strs, ft_strtablen(strs));
			ft_error();
		}
	}
	ft_freestrs(strs, i);
}

void	ft_many_arg(char **nbr, int arg, t_list **a)
{
	int			i;
	int long	content;

	i = 1;
	while (i <= (arg - 1))
	{
		if (is_it_nbr(nbr[i]) == 1)
		{
			content = ft_atol(nbr[i++], a);
			ft_lst_add_back(a, ft_lstnew(content));
		}
		else
		{
			ft_free_tab(*a);
			ft_error();
		}
	}
}

t_list	**ft_parse(char **nbr, int arg, t_list **a)
{
	int			i;

	i = 1;
	if (arg == 1)
		return (exit(0), a);
	if (arg > 2)
		ft_many_arg(nbr, arg, a);
	else if (arg == 2)
		ft_one_arg(nbr, a);
	return (a);
}

int	is_it_already_sorted(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	if (!a)
	{
		ft_free_tab(a);
		ft_error();
	}
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	a = tmp;
	return (1);
}
