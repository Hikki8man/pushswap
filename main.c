//
// Created by Johan Chevet on 5/28/21.
//
#include "push_swap.h"

void printlst(t_data *data, t_lst *lst, char c)
{
	t_lst *tmp;

    printf("\n");
	tmp = lst;
	printf("List %c\n", c);
	while (tmp)
	{
		printf("nb = %d | pos = %d\n", tmp->nb, tmp->pos);
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
	elem->pos = -1;
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
	{
		num *= -1;
		s++;
		len--;
	}
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

char	**str_to_tab(char *str)
{
	char	**tab;
	
	tab = ft_split(str, ' ');
	if (tab == NULL)
		exit(1);
	return (tab);
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

int find_biggest(t_lst **a)
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
		if (l->nb > tmp)
		{
			tmp = l->nb;
			j = i;
		}
		l = l->next;
		i++;
	}
	return (tmp);
}

void push_smallest_to_b(t_lst **a, t_lst **b, int smallest_pos)
{
	int i;
	
	i = 1;
	if (smallest_pos <= lstsize(*a) / 2 + lstsize(*a) % 2)
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

void freelst(t_lst **a)
{
	t_lst *tmp;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		(*a) = tmp;
	}
}

void exit_err(t_lst **a, int err)
{
	freelst(a);
	if (err == 1)
		ft_putstr_fd("Error\nWrong arguments\n", 2);
	if (err == 2)
		ft_putstr_fd("Error\nDuplicates numbers\n", 2);
	exit(1);
}

void tab_to_list(char **av, int ac, t_lst **a)
{
	int nb;
	int	i;
	
	i = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (str_int_cmp(av[i], nb) == -1)
			exit_err(a, 1);
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

int tab_len(char **t)
{
	int	i;
	
	i = 0;
	while (t[i])
		i++;
	return (i);
}

static void free_tab(char **t)
{
	int	i;
	
	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

t_lst 	*lst_cpy(t_lst *a)
{
	t_lst *cpy;
	
	cpy = NULL;
	while (a)
	{
		add_back(&cpy, new_elem(a->nb));
		a = a->next;
	}
	return (cpy);
}

void push_to_trash(t_lst **a, t_lst **trash)
{
	t_lst *tmp;
	
	if (is_empty(a))
		return;
	tmp = (*a);
	(*a) = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = (*trash);
	if (*trash)
		(*trash)->prev = tmp;
	(*trash) = tmp;
}

void rotate_silent(t_lst **lst)
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
}

void set_pos(t_lst **a)
{
	int 	size;
	int		i;
	int 	j;
	int 	smol;
	t_lst 	*cpy;
	t_lst	*pt_a;
	t_lst	*trash;
	
	i = -1;
	trash = NULL;
	cpy = lst_cpy(*a);
	size = lstsize(*a);
	while (++i < size)
	{
		j = -1;
		pt_a = (*a);
		smol = find_smallest(&cpy) - 1;
		while (++j < smol)
			rotate_silent(&cpy);
		while (pt_a->nb != cpy->nb)
			pt_a = pt_a->next;
		pt_a->pos = i;
		push_to_trash(&cpy, &trash);
	}
	freelst(&trash);
}

void set_chunk(t_chunk *chunk, int size, int lstsize)
{
	int	i;
	int min;
	int max;
	
	min = 0;
	max = (lstsize / 5) - 1;
	i = -1;
	while (++i < size)
	{
		chunk[i].min = min;
		chunk[i].max = max;
		min += lstsize / 5;
		max += lstsize / 5;
	}
	chunk[i - 1].max = lstsize - 1;
}

void insert_sort(t_lst **a, t_lst **b)
{
	int	i;
	int	size;
	
	i = -1;
	size = lstsize(*a);
	set_pos(a);
	while (++i < size)
		push_smallest_to_b(a, b, find_smallest(a));
	i = -1;
	size = lstsize(*b);
	while (++i < size)
		push(b, a, 'a');
}

int index_elem(t_lst *l, int pos)
{
	int i;

	i = 0;
	while (pos != l->pos)
	{
		i++;
		l = l->next;
	}
	return (i);
}


void find_shortest_way_and_rotate(t_lst **a, t_lst **b, int pos, char c)
{
	int	size;
	int index;

	size = lstsize(*a);
	index = index_elem(*a, pos);
	if (index <= size / 2 + size % 2)
		while ((*a)->pos != pos)
			rotate(a, c);
	else
	{
		while ((*a)->pos != pos)
			rev_rotate(a, c);
	}
}

char 	compare_nb_moves(t_lst **a, int first, int sec)
{
	int	index_first;
	int index_sec;
	int size;
	
	index_first = index_elem(*a, first);
	index_sec = index_elem(*a, sec);
	size = lstsize(*a);
	if (index_first > size / 2)
		index_first -= size;
	if (index_sec > size / 2)
		index_sec = size - index_sec;
	if (index_first <= index_sec)
		return ('f');
	return ('s');
}

void insert_sort_chunk(t_lst **a, t_lst **b)
{
	int	size;
	int	nb_chunks;
	t_chunk chunk[5];
	t_lst *top;
	t_lst *bottom;
	int	hold_first;
	int hold_second;
	int i;
	
	nb_chunks = 5;
	size = lstsize(*a);
	set_chunk(chunk, nb_chunks, lstsize(*a));
	set_pos(a);
	i = 0;
//		for (int i = 0; i < 5; i++)
//		printf("chunk %d : min = %d | max = %d\n", i, chunk[i].min, chunk[i].max);
	while (i < nb_chunks)
	{
		hold_first = -1;
		hold_second = -1;
		top = *a;
		bottom = lstlast(*a);
		while (top)
		{
			if (top->pos >= chunk[i].min && top->pos <= chunk[i].max)
			{
				hold_first = top->pos;
				break;
			}
			top = top->next;
		}
		while (bottom)
		{
			if (hold_first == -1)
				break;
			if (bottom->pos >= chunk[i].min && bottom->pos <= chunk[i].max)
			{
				hold_second = bottom->pos;
				break;
			}
			bottom = bottom->prev;
		}
		if (hold_first == -1)
			i++;
		else
		{
			if (compare_nb_moves(a, hold_first, hold_second) == 'f')
				find_shortest_way_and_rotate(a, b, hold_first, 'a');
			else
				find_shortest_way_and_rotate(a, b, hold_second, 'a');
			push(a, b, 'b');
//			if ((*b)->next && (*b)->pos < (*b)->next->pos)
//				rotate(b, 'b');
		}
	}

	while (*b)
	{
		int big = find_biggest(b);
		while ((*b)->pos != big) // why ??
			find_shortest_way_and_rotate(b, a, big, 'b');
		push(b, a, 'a');
	}
}

int main(int ac, char **av)
{
	t_lst *a;
	t_lst *b;
	t_data data;
	char	**tab;
	
//	av[1] = "-4";
//	av[2] = "2";
//	av[3] = "1";
//	av[4] = "3";
//	av[5] = "6";
//	av[1] = "44 2 4 5 -2 3 6 1 0";
//	av[1] = "3645 7701 8 5099 5869 6486 7214 3969 1236 6649 3718 2158 8349 444 1450 1924 3392 2220 2908 4619 3210 3539 9854 5078 2725 418 2500 2740 9412 3983 1913 4078 5282 6517 3587 5580 5488 8876 6775 3141 5938 7295 3349 8880 9222 1183 1597 4639 3230 3419 2189 6320 2288 7778 1332 2626 3567 5259 2236 2271 5142 346 241 8271 9266 3343 3183 6590 9524 4611 9133 9402 4681 3454 2279 6823 5770 4677 2695 3167 6991 2387 955 4429 1564 1043 1278 4116 6085 9356 5961 2374 7324 3775 2080 5555 12 2826 1108 5450";
	av[1] = "50 79 8 75 61 51 16 46 26 37 23 38 19 81 12 89 72 92 39 63 11 74 87 31 85 99 1 53 35 64 48 59 56 10 43 70 52 65 42 76 62 60 83 86 3 21 45 82 27 54 18 95 15 71 25 88 84 2 9 34 13 78 41 58 33 28 96 97 0 55 98 32 30 6 7 67 44 90 29 91 94 57 5 77 20 93 22 49 40 36 24 4 47 69 14 80 17 73 66 68";
//	av[7] = "117";
//	av[8] = "55";
//	av[9] = "77";
//	av[10] = "88";
	ac = 2;
	init_lst(&a, &b);
	av++;
	ac--;
	if (ac >= 1)
	{
		if (ac == 1)
		{
			tab = str_to_tab(av[0]);
			tab_to_list(tab, tab_len(tab), &a);
			free_tab(tab);
			ac = tab_len(tab) + 1;
		}
		else
			tab_to_list(av, ac, &a);
		if (check_duplicates(a))
			exit_err(&a, 2);
		if (is_list_sorted(a))
			exit_err(&a, 0);
//		printlst(&data, a, 'A');
		if (ac == 3)
			sort3(&a);
		else if (ac == 5)
        	sort5(&a, &b);
		else
			insert_sort_chunk(&a, &b);
//set_pos(&a);
//		while (a)
//		{
//			int big = find_biggest(&a);
//			int l = 0;
//			while (a->pos != big)
//			{
//		find_shortest_way_and_rotate(b, a, find_biggest(b), 'b');
//				rotate(&a, 'a');
//				l++;
//			}
//			push(&a, &b, 'a');
//		}
//       printlst(&data, a, 'A');
//        printlst(&data, b, 'B');
		exit_err(&a, 0);
	}
	return (1);
}