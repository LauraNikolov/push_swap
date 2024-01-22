

#include "test.h"
#include <stdio.h>

t_list	**ft_parse(char **nbr, int arg, t_list **a)
{
	int long	content;
	int			i;
	char		**strs;

	i = 1;
	if (arg > 2)
	{
		while (i <= (arg - 1))
		{
			content = 0;
			content = ft_atol(nbr[i++]);
			ft_lst_add_back(a, ft_lstnew(content));
		}
	}
	if (arg == 2)
	{
		i = 0;
		strs = ft_split(nbr[1], ' ');
		while (strs[i++])
		{
			content = ft_atol(strs[i]);
			ft_lst_add_back(a, ft_lstnew(content));
		}

	}
	return (a);
}
/* La pile a contient une quantité aléatoire de négatif et/ou des nombres positifs
qui ne peuvent pas être dupliqués.
◦ La pile b est vide. */

int	ft_arg_is_ok(t_list *a)
{
	int		tmp_content;
	t_list	*save;
	t_list *head;

	save = a;
	head = a;
	while (save)
	{
		tmp_content = save->content;
		while (a)
		{
			if (tmp_content == a->content && save != a)
				exit(0);
			a = a->next;
		}
		a = head;
		save = save->next;
	}
	return (1);
}