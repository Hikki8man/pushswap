//
// Created by Johan Chevet on 6/10/21.
//

#include "../include/push_swap.h"

t_chunk	*set_chunk(t_chunk *chunk, int size, int lstsize)
{
	int	i;
	int	min;
	int	max;

	chunk = malloc(sizeof(t_chunk) * size);
	min = 0;
	max = (lstsize / size) - 1;
	i = -1;
	while (++i < size)
	{
		chunk[i].min = min;
		chunk[i].max = max;
		min += lstsize / size;
		max += lstsize / size;
	}
	chunk[i - 1].max = lstsize - 1;
	return (chunk);
}

int	is_list_sorted(t_lst *a)
{
	int		tmp;
	t_lst	*l;

	l = a;
	while (l)
	{
		a = l;
		tmp = a->nb;
		a = a->next;
		while (a)
		{
			if (tmp > a->nb)
				return (0);
			a = a->next;
		}
		l = l->next;
	}
	return (1);
}

char 	compare_nb_moves(t_lst **a, int first, int sec)
{
	int	index_first;
	int	index_sec;
	int	size;

	index_first = index_elem(*a, first);
	index_sec = index_elem(*a, sec);
	size = lstsize(*a);
	if (index_first > size / 2)
		index_first -= size;
	if (index_sec > size / 2)
		index_sec = size - index_sec;
	if (index_first <= index_sec)
		return ('f');
	return ('s');
}

int	index_elem(t_lst *l, int pos)
{
	int	i;

	i = 0;
	if (is_empty(&l))
		return (0);
	while (pos != l->pos)
	{
		i++;
		l = l->next;
	}
	return (i);
}

void	push_smallest_to_b(t_lst **a, t_lst **b, int smallest_pos, int silent)
{
	int	i;
	int	size;

	i = -1;
	size = lstsize(*a);
	if (smallest_pos <= (size / 2 + size % 2))
		while (++i < smallest_pos)
			rotate(a, 'a', 0);
	else
	{
		while (smallest_pos < size)
		{
			rev_rotate(a, 'a', silent);
			smallest_pos++;
		}
	}
	push(a, b, 'b', 0);
}
