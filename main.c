//
// Created by Johan Chevet on 5/28/21.
//
#include "push_swap.h"

void printlst(t_data *data, t_lst *lst, int nb_elem)
{
	int i;
	t_lst *tmp;
	i = 0;

	tmp = lst;
	while (i < nb_elem)
	{
		printf("nb = %d\n", tmp->nb);
		tmp = tmp->next;
		i++;
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

void push(t_data *data, t_lst *a, t_lst *b)
{
	t_lst *tmp;

	tmp = a;
	a = a->next;
	b = tmp;
	data->a_size--;
	data->b_size++;
	printlst(data, a, data->a_size);
	printlst(data, b, data->b_size);


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

t_lst *split_to_list(t_data *data, char *str)
{
	t_lst	*lst;
	int nb;

	lst = NULL;
	while (*str)
	{
		str += skip_space(str);
		nb = ft_atoi(str);
		add_back(&lst, new_elem(nb));
		str += intlen(nb);
		data->a_size++;
	}
	return (lst);
}

int main(int ac, char **av)
{
	t_lst *a;
	t_lst *b;

	b = NULL;
	t_data data;

	data.a_size = 0;
	data.b_size = 0;
//	if (ac == 2)
//	{
		av[1] = "1 2 3 4 5 6";
		a = split_to_list(&data, av[1]);
		printlst(&data, a, data.a_size);
		push(&data, a, b);
		printlst(&data, a, data.a_size);
//	}
//	printf("argumeeeeeent");
	return (1);
}