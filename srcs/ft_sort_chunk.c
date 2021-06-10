//
// Created by Johan Chevet on 6/10/21.
//

#include "../include/push_swap.h"

static int	return_first_in_chunk(t_lst *top, t_chunk chunk)
{
	while (top)
	{
		if (top->pos >= chunk.min && top->pos <= chunk.max)
			return (top->pos);
		top = top->next;
	}
	return (-1);
}

static int	return_last_in_chunk(t_lst *bottom, t_chunk chunk)
{
	while (bottom)
	{
		if (bottom->pos >= chunk.min && bottom->pos <= chunk.max)
			return (bottom->pos);
		bottom = bottom->prev;
	}
	return (-1);
}

static void	push_b_to_a(t_lst **a, t_lst **b, int silent)
{
	while (*b)
	{
		find_shortest_way_and_rotate(b, find_biggest(b), 'b', silent);
		push(b, a, 'a', silent);
	}
}

void	sort_chunk(t_lst **a, t_lst **b, int nb_chunks, int silent)
{
	t_chunk	*chunk;
	int		first;
	int		second;
	int		i;

	i = 0;
	chunk = NULL;
	chunk = set_chunk(chunk, nb_chunks, lstsize(*a));
	while (i < nb_chunks)
	{
		first = return_first_in_chunk(*a, chunk[i]);
		second = return_last_in_chunk(lstlast(*a), chunk[i]);
		if (first == -1)
			i++;
		else
		{
			if (compare_nb_moves(a, first, second) == 'f')
				find_shortest_way_and_rotate(a, first, 'a', silent);
			else
				find_shortest_way_and_rotate(a, second, 'a', silent);
			push(a, b, 'b', silent);
		}
	}
	push_b_to_a(a, b, silent);
	free(chunk);
}
