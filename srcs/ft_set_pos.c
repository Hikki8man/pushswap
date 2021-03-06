//
// Created by Stellar on 09/06/2021.
//

#include "../include/push_swap.h"

static void	push_to_trash(t_lst **a, t_lst **trash)
{
	t_lst	*tmp;

	if (is_empty(a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = (*trash);
	if (*trash)
		(*trash)->prev = tmp;
	(*trash) = tmp;
}

static int	find_smallest_nb(t_lst **a)
{
	t_lst	*l;
	int		tmp;

	l = *a;
	tmp = l->nb;
	while (l)
	{
		if (l->nb < tmp)
			tmp = l->nb;
		l = l->next;
	}
	return (tmp);
}

void	set_pos(t_lst **a)
{
	int		i;
	t_lst	*cpy;
	t_lst	*pt_a;
	t_lst	*trash;

	i = 0;
	trash = NULL;
	cpy = lst_cpy(*a);
	while (cpy)
	{
		pt_a = (*a);
		while (cpy->nb != find_smallest_nb(&cpy))
			rotate(&cpy, 'c', 1);
		while (pt_a->nb != cpy->nb)
			pt_a = pt_a->next;
		pt_a->pos = i;
		push_to_trash(&cpy, &trash);
		i++;
	}
	freelst(&trash);
}
