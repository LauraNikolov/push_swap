/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:43:02 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 16:37:44 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

long	ft_atol(const char *s, t_list **a)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (s == NULL)
		return (0);
	while ((s[i] == ' ') || (s[i] >= 7 && s[i] <= 13))
		i++;
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	if (result * sign > 2147483647 || result * sign < -2147483648)
		return (ft_free_tab(*a), ft_error(), 0);
	return ((result) * (sign));
}

int	is_it_nbr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_arg_is_ok(t_list *a)
{
	int		tmp_content;
	t_list	*save;
	t_list	*head;
	t_list	*tmp;

	save = a;
	head = a;
	tmp = a;
	while (save)
	{
		tmp_content = save->content;
		while (a)
		{
			if (tmp_content == a->content && save != a)
				return (ft_free_tab(tmp), ft_error(), 0);
			a = a->next;
		}
		a = head;
		save = save->next;
	}
	if (is_it_already_sorted(a) == 1)
		(ft_free_tab(a), exit(0), 0);
	return (1);
}

int	ft_strtablen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
