//
// Created by Johan Chevet on 6/10/21.
//

#include "../include/push_swap.h"

int	find_smallest(t_lst **a)
{
	t_lst	*l;
	int		tmp;

	l = *a;
	tmp = l->pos;
	while (l)
	{
		if (l->pos < tmp)
			tmp = l->pos;
		l = l->next;
	}
	return (tmp);
}

int	find_biggest(t_lst **a)
{
	t_lst	*l;
	int		tmp;

	l = *a;
	tmp = l->pos;
	while (l)
	{
		if (l->pos > tmp)
			tmp = l->pos;
		l = l->next;
	}
	return (tmp);
}

void	find_shortest_way_and_rotate(t_lst **l, int pos, char c, int silent)
{
	int	size;
	int	index;

	size = lstsize(*l);
	index = index_elem(*l, pos);
	if (index <= size / 2 + size % 2)
		while ((*l)->pos != pos)
			rotate(l, c, silent);
	else
		while ((*l)->pos != pos)
			rev_rotate(l, c, silent);
}

int	is_empty(t_lst **lst)
{
	if (!*lst)
		return (1);
	return (0);
}
