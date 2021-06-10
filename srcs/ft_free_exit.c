//
// Created by Johan Chevet on 6/10/21.
//

#include "../include/push_swap.h"

void	freelst(t_lst **a)
{
	t_lst	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		(*a) = tmp;
	}
}

//void 	free_chunk(t_chunk *chunk, int size)
//{
//	int i;
//
//	i = -1;
//	while (++i < size)
//		free(chunk + i);
//}

void	exit_err(t_lst **a, t_lst **b)
{
	freelst(a);
	freelst(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
