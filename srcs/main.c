//
// Created by Johan Chevet on 5/28/21.
//
#include "../include/push_swap.h"

void	printlst(t_lst *lst, char c)
{
	t_lst	*tmp;

	ft_printf("\n");
	tmp = lst;
	ft_printf("List %c\n", c);
	while (tmp)
	{
		ft_printf("nb = %d | pos = %d\n", tmp->nb, tmp->pos);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;
	int		silent;

	silent = 0;
	parsing(&ac, av, &a, &b);
	if (!is_list_sorted(a))
	{
		if (ac == 3)
			sort3(&a, silent);
		else if (ac == 5)
			sort5(&a, &b, silent);
		else if (ac <= 200)
			sort_chunk(&a, &b, 5, silent);
		else
			sort_chunk(&a, &b, 11, silent);
	}
	freelst(&a);
	return (0);
}
