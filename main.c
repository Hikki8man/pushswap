//
// Created by Johan Chevet on 5/28/21.
//
#include "push_swap.h"

void printlst(t_data *data, t_lst *lst, char c)
{
	int i;
	t_lst *tmp;
	i = 0;

    printf("\n");
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
	elem->prev = NULL;
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
		new->prev = tmp;
		tmp->next = new;
	}
}

static void add_front(t_lst **lst, t_lst *elem)
{
	elem->next = *lst;
	*lst = elem;
}
void swap(t_lst *lst, char c)
{
	int tmp;

	if (lst->next != NULL || lst == NULL)
	{
		tmp = lst->next->nb;
		lst->next->nb = lst->nb;
		lst->nb = tmp;
	}
	printf("s%c\n", c);
}

void push(t_lst **a, t_lst **b, char c)
{
	t_lst *tmp;

	if (is_empty(a))
		return;
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


int intlen(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	printf("ok\n");
	return (i);
}

int str_int_cmp(char *s, int nb)
{
	int			len;
	int			mod;
	long long	num;
	
	len = ft_strlen(s);
	num = nb;
	if (!ft_strncmp(s, "2147483648", 10))
		return (-1);
	if (nb < 0)
		num *= -1;
	while (len-- > 0)
	{
		mod = num % 10 + 48;
		if (mod != (int)s[len])
			return (-1);
		num /= 10;
	}
	return (0);
}

void	str_to_list(char *str, t_lst **l)
{
	int nb;
	t_lst *a;

	while (*str)
	{
		str += skip_space(str);
		nb = ft_atoi(str);
		add_back(&a, new_elem(nb));
		str += intlen(nb);
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

static void	init_lst(t_lst **a, t_lst **b)
{
	*a = NULL;
	*b = NULL;
}

void rotate(t_lst **lst, char c)
{
	t_lst *first;
	t_lst *tmp;

	first = (*lst)->next;
	first->prev = NULL;
	tmp = lstlast(*lst);
	tmp->next = *lst;
    (*lst)->prev = tmp;
	(*lst)->next = NULL;
	*lst = first;
	printf("r%c\n", c);
}

void rev_rotate(t_lst **lst, char c)
{
	t_lst	*last;
	t_lst	*tmp;
	int size;
	int	i;

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

void    sort3(t_lst **a)
{
    if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb && (*a)->nb < (*a)->next->next->nb)
        swap(*a, 'a');
    else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb)
    {
        swap(*a, 'a');
        rev_rotate(a, 'a');
    }
    else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb)
        rotate(a, 'a');
    else if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb && (*a)->nb < (*a)->next->next->nb)
    {
        swap(*a, 'a');
        rotate(a, 'a');
    }
    else if ((*a)->nb < (*a)->next->nb && (*a)->nb > (*a)->next->next->nb)
        rev_rotate(a, 'a');
}

int find_smallest(t_lst **a)
{
    t_lst   *l;
    int     i;
    int     j;
    int     tmp;

    i = 1;
    j = 1;
    l = *a;
    tmp = l->nb;
    while (l)
    {
        if (l->nb < tmp)
        {
            tmp = l->nb;
            j = i;
        }
        l = l->next;
        i++;
    }
    return (j);
}

void push_smallest_to_b(t_lst **a, t_lst **b, int smallest_pos)
{
	int i;
	
	i = 1;
	if (smallest_pos <= lstsize(*a) / 2 || (smallest_pos == 3 && lstsize(*a) == 5))
		while (i < smallest_pos)
		{
			rotate(a, 'a');
			i++;
		}
	else
	{
		while (smallest_pos <= lstsize(*a))
		{
			rev_rotate(a, 'a');
			smallest_pos++;
		}
	}
	push(a, b, 'b');
}

void sort5(t_lst **a, t_lst **b)
{
    push_smallest_to_b(a, b, find_smallest(a));
	push_smallest_to_b(a, b, find_smallest(a));
	sort3(a);
	push(b, a, 'a');
	push(b, a, 'a');
}

void freelst(t_lst **a, int err)
{
	t_lst *tmp;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		(*a) = tmp;
	}
	if (err == 1)
		ft_putstr_fd("Error\nWrong arguments\n", 2);
	if (err == 2)
		ft_putstr_fd("Error\nDuplicates numbers\n", 2);
	exit(1);
}

void tab_to_list(char **av, int ac, t_lst **a)
{
	int	i;
	int nb;

	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (str_int_cmp(av[i], nb) == -1)
			freelst(a, 1);
		add_back(a, new_elem(nb));
		i++;
	}
}

int check_duplicates(t_lst *a)
{
	int		tmp;
	t_lst 	*l;

	l = a;
	while (l)
	{
		a = l;
		tmp = a->nb;
		a = a->next;
		while (a)
		{
			if (tmp == a->nb)
				return (1);
			a = a->next;
		}
		l = l->next;
	}
	return (0);


}

int is_list_sorted(t_lst *a)
{
	int		tmp;
	t_lst 	*l;

	l = a;
	while (l)
	{
		a = l;
		tmp = a->nb;
		a = a->next;
		while (a)
		{
			if (tmp > a->nb)
				return (0);
			a = a->next;
		}
		l = l->next;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_lst *a;
	t_lst *b;

	t_data data;

	av[1] = "4";
	av[2] = "2";
	av[3] = "1";
	av[4] = "3";
	av[5] = "21";
//	av[1] = "1";
//	av[2] = "2";
//	av[3] = "3";
//	av[4] = "4";
//	av[5] = "21";
	ac = 6;
	init_lst(&a, &b);
	if (ac >= 2)
	{
		if (ac == 2)
			str_to_list(av[1], &a);
		else
			tab_to_list(av, ac, &a);
		if (check_duplicates(a))
			freelst(&a, 2);
		if (is_list_sorted(a))
			freelst(&a, 0);
		printlst(&data, a, 'A');
        sort5(&a, &b);
       printlst(&data, a, 'A');
//        printlst(&data, b, 'B');

	}
	printf("argumeeeeeent");
	return (1);
}