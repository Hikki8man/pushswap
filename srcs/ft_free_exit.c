//
// Created by Johan Chevet on 6/10/21.
//

#include "../include/push_swap.h"

void	freelst(t_lst **a)
{
	t_lst	*tmp;

	if (a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			(*a) = tmp;
		}
	}
}

void	exit_err(t_lst **a, t_lst **b)
{
	freelst(a);
	freelst(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
