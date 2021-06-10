//
// Created by Johan Chevet on 6/10/21.
//

#include "../include/push_swap.h"

void	sort3(t_lst **a, int silent)
{
	if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb \
	&& (*a)->nb < (*a)->next->next->nb)
		swap(*a, 'a', silent);
	else if ((*a)->nb > (*a)->next->nb \
	&& (*a)->next->nb > (*a)->next->next->nb)
	{
		swap(*a, 'a', silent);
		rev_rotate(a, 'a', silent);
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb)
		rotate(a, 'a', silent);
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb \
	&& (*a)->nb < (*a)->next->next->nb)
	{
		swap(*a, 'a', silent);
		rotate(a, 'a', silent);
	}
	else if ((*a)->nb < (*a)->next->nb && (*a)->nb > (*a)->next->next->nb)
		rev_rotate(a, 'a', silent);
}
