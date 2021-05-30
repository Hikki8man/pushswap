//
// Created by Johan Chevet on 5/28/21.
//
#include "push_swap.h"

void printlst(t_data *data, t_lst *lst, char c)
{
	int i;
	t_lst *tmp;
	i = 0;

	tmp = lst;
	printf("List %c\n", c);
	while (tmp)
	{
		printf("nb = %d\n", tmp->nb);
		tmp = tmp->next;
	}
	printf("\n");
}

int	skip_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

int is_empty(t_lst **lst)
{
	if (!*lst)
		return (1);
	return (0);
}

static t_lst	*lstlast(t_lst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

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
	t_lst	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = lstlast(*lst);
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

void push(t_data *data, t_lst **a, t_lst **b)
{
	t_lst *tmp;

	if (is_empty(a))
		return;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next =(*b);
	(*b) = tmp;
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

void	split_to_list(t_data *data, char *str, t_lst **l)
{
	int nb;
	t_lst *a;

	while (*str)
	{
		str += skip_space(str);
		nb = ft_atoi(str);
		add_back(&a, new_elem(nb));
		str += intlen(nb);
		data->a_size++;
	}
	*l = a;
}

int	lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static void	init_lst(t_lst *a, t_lst *b)
{
	a = NULL;
	b = NULL;
}

void rotate(t_lst **lst)
{
	t_lst *first;
	t_lst *tmp;

	first = (*lst)->next;
	tmp = lstlast(*lst);
	tmp->next = *lst;
	(*lst)->next = NULL;
	*lst = first;
}

void rev_rotate(t_lst **lst)
{
	t_lst	*last;
	t_lst	*tmp;
	int size;
	int	i;

	i = 0;
	size = lstsize(*lst);
	last = lstlast(*lst);
	last->next = *lst;
	tmp = *lst;
	while (i < size - 2)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	*lst = last;
}

int main(int ac, char **av)
{
	t_lst *a;
	t_lst *b;

	t_data data;

	init_lst(a, b);
//	if (ac == 2)
//	{
		av[1] = "1 2 3 4 5 6";
		split_to_list(&data, av[1], &a);
		printlst(&data, a, 'A');
		printlst(&data, b, 'B');
//		push(&data, &b, &a);
//		swap(a);
		rev_rotate(&a);
		printlst(&data, a, 'A');
		printlst(&data, b, 'B');
	rev_rotate(&a);
	printlst(&data, a, 'A');

//	}
//	printf("argumeeeeeent");
	return (1);
}