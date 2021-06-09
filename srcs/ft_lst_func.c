//
// Created by Johan Chevet on 6/9/21.
//

#include "../include/push_swap.h"

t_lst	*new_elem(int nb)
{
	t_lst	*elem;

	elem = malloc(sizeof(t_lst));
	if (elem == NULL)
		exit (1);
	elem->nb = nb;
	elem->pos = -1;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

void	add_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = lstlast(*lst);
		new->prev = tmp;
		tmp->next = new;
	}
}

t_lst 	*lst_cpy(t_lst *a)
{
	t_lst	*cpy;

	cpy = NULL;
	while (a)
	{
		add_back(&cpy, new_elem(a->nb));
		a = a->next;
	}
	return (cpy);
}

t_lst	*lstlast(t_lst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
