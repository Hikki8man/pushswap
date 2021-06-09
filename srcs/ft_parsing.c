//
// Created by Stellar on 09/06/2021.
//

#include "../include/push_swap.h"


static int check_duplicates(t_lst *a)
{
	int		tmp;
	t_lst 	*l;

	l = a;
	while (l)
	{
		a = l;
		tmp = a->nb;
		a = a->next;
		while (a)
		{
			if (tmp == a->nb)
				return (1);
			a = a->next;
		}
		l = l->next;
	}
	return (0);
}

static void free_tab(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

static int tab_len(char **t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}

static void tab_to_list(char **av, int ac, t_lst **a)
{
	int nb;
	int	i;

	i = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (str_int_cmp(av[i], nb) == -1)
			exit_err(a, 1);
		add_back(a, new_elem(nb));
		i++;
	}
}

void parsing(int *ac, char **av, t_lst **a, t_lst **b)
{
	char	**tab;

	init_lst(a, b);
	av++;
	(*ac)--;
	if (*ac >= 1)
	{
		if (*ac == 1)
		{
			tab = str_to_tab(av[0]);
			tab_to_list(tab, tab_len(tab), a);
			*ac = tab_len(tab);
			free_tab(tab);
		}
		else
			tab_to_list(av, *ac, a);
		if (check_duplicates(*a))
			exit_err(a, 2);
		if (is_list_sorted(*a))
			exit_err(a, 0);
		set_pos(a);
	}
}