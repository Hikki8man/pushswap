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

void	sort500(t_lst **a, t_lst **b, t_info *info)
{
	sort_chunk(a, b, 4, info);
	ft_swap(&info->fst, &info->sec);
//	printlst(*a, 'a');
//	printlst(*b, 'b');
	sort_chunk(b, a, 8, info);
//	printlst(*a, 'a');
//	printlst(*b, 'b');
	ft_swap(&info->fst, &info->sec);
	sort_chunk(a, b, 11, info);
//	printlst(*a, 'a');
//	printlst(*b, 'b');
	push_list(b, a, info);

}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;
	t_info	info;
	int		silent;

	silent = 0;
	info.silent = 0;
	info.fst = 'a';
	info.sec = 'b';
	parsing(&ac, av, &a, &b);
	if (!is_list_sorted(a))
	{
		if (ac == 3)
			sort3(&a, silent);
		else if (ac == 5)
			sort5(&a, &b, silent);
		else if (ac <= 200) {
			sort_chunk(&a, &b, 5, &info);
			push_list(&b, &a, &info);
		}
		else {
			sort500(&a, &b, &info);
		}
	}
//	printlst(a, 'a');
	freelst(&a);
	return (0);
}
