//
// Created by Johan Chevet on 6/9/21.
//

#include "../include/push_swap.h"

void	swap(t_lst *lst, char c)
{
	int	tmp;
	int	tmp2;

	if (lst->next != NULL || lst == NULL)
	{
		tmp = lst->next->nb;
		tmp2 = lst->next->pos;
		lst->next->nb = lst->nb;
		lst->next->pos = lst->pos;
		lst->nb = tmp;
		lst->pos = tmp2;
	}
	printf("s%c\n", c);
}

void	rotate(t_lst **lst, char c)
{
	t_lst	*first;
	t_lst	*tmp;

	first = (*lst)->next;
	first->prev = NULL;
	tmp = lstlast(*lst);
	tmp->next = *lst;
	(*lst)->prev = tmp;
	(*lst)->next = NULL;
	*lst = first;
	printf("r%c\n", c);
}

void	rev_rotate(t_lst **lst, char c)
{
	t_lst	*last;
	t_lst	*tmp;
	int		size;
	int		i;

	i = 0;
	size = lstsize(*lst);
	last = lstlast(*lst);
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	tmp = *lst;
	while (i < size - 2)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	*lst = last;
	printf("rr%c\n", c);
}

void	push(t_lst **a, t_lst **b, char c)
{
	t_lst	*tmp;

	if (is_empty(a))
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = (*b);
	if (*b)
		(*b)->prev = tmp;
	(*b) = tmp;
	printf("p%c\n", c);
}
