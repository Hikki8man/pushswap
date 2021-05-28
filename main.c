//
// Created by Johan Chevet on 5/28/21.
//

#include "push_swap.h"

t_lst *new_elem(int nb)
{
	t_lst *elem;

	elem = malloc(sizeof(t_lst));
	if (elem == NULL)
		exit (1);
	elem->nb = nb;
	elem->next = NULL;
	return (elem);
}

static void	add_back(t_lst **lst, t_lst *new)
{
	t_list	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

static void add_front(t_lst **lst, t_lst *elem)
{
	elem->next = *lst;
	*lst = elem;
}
void swap(t_lst *lst)
{
	int tmp;

	if (lst->next != NULL || lst == NULL)
	{
		tmp = lst->next->nb;
		lst->next->nb = lst->nb;
		lst->nb = tmp;
	}
}

void printlst(t_struct *lst)
{
	int i;
	t_lst *tmp;
	i = 0;

	tmp = lst->a;
	while (i < lst->nb_elem)
	{
		printf("nb = %d\n", tmp->nb);
		tmp = tmp->next;
		i++;
	}
}

int intlen(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void split_to_list(t_lst *lst, char *str)
{
	int nb;

	while (*str)
	{
		nb = ft_atoi(str);
		add_back(&lst, new_elem(nb));
		str += intlen(nb);
		nb_elem++;
	}
}

int main(int ac, char **av)
{
	t_lst *a;

	if (ac == 2)
	{

	}

	return (1);
}