//
// Created by Johan Chevet on 5/28/21.
//
#include "../include/push_swap.h"

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

int is_empty(t_lst **lst)
{
	if (!*lst)
		return (1);
	return (0);
}

int index_elem(t_lst *l, int pos)
{
	int i;
	
	i = 0;
	if (is_empty(&l))
		return (0);
	while (pos != l->pos)
	{
		i++;
		l = l->next;
	}
	return (i);
}

int	skip_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
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



static void	init_lst(t_lst **a, t_lst **b)
{
	*a = NULL;
	*b = NULL;
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
    int     tmp;
    
    l = *a;
    tmp = l->pos;
    while (l)
    {
        if (l->pos < tmp)
            tmp = l->pos;
        l = l->next;
    }
    return (tmp);
}

int find_biggest(t_lst **a)
{
	t_lst   *l;
	int     tmp;
	
	l = *a;
	tmp = l->pos;
	while (l)
	{
		if (l->pos > tmp)
			tmp = l->pos;
		l = l->next;
	}
	return (tmp);
}

void push_smallest_to_b(t_lst **a, t_lst **b, int smallest_pos)
{
	int	i;
	int	size;
	
	i = 0;
	size = lstsize(*a);
	if (smallest_pos <= size / 2 + size % 2)
		while (i < smallest_pos)
		{
			rotate(a, 'a');
			i++;
		}
	else
	{
		while (smallest_pos < size)
		{
			rev_rotate(a, 'a');
			smallest_pos++;
		}
	}
	push(a, b, 'b');
}

void sort5(t_lst **a, t_lst **b)
{
    push_smallest_to_b(a, b, index_elem(*a, find_smallest(a)));
	push_smallest_to_b(a, b, index_elem(*a, find_smallest(a)));
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
		add_back(a, new_elem(nb)); //TODO add front ?
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

int find_smallest_nb(t_lst **a)
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
		smol = find_smallest_nb(&cpy) - 1;
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
	max = (lstsize / size) - 1;
	i = -1;
	while (++i < size)
	{
		chunk[i].min = min;
		chunk[i].max = max;
		min += lstsize / size;
		max += lstsize / size;
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

void insert_sort_chunk(t_lst **a, t_lst **b, int nb_chunks)
{
	int	size;
	t_chunk chunk[nb_chunks];
	t_lst *top;
	t_lst *bottom;
	int	hold_first;
	int hold_second;
	int i;
	
	size = lstsize(*a);
	set_chunk(chunk, nb_chunks, lstsize(*a));
	set_pos(a);
	i = 0;
//		for (int i = 0; i < nb_chunks; i++)
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
		}
	}

	while (*b)
	{
		find_shortest_way_and_rotate(b, a, find_biggest(b), 'b');
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
	av[1] = "4 5 2 3 1";
//	av[3] = "1";
//	av[4] = "3";
//	av[5] = "6";
//	av[1] = "44 2 4 5 -2 3 6 1 0";
//	av[1] = "3645 7701 8 5099 5869 6486 7214 3969 1236 6649 3718 2158 8349 444 1450 1924 3392 2220 2908 4619 3210 3539 9854 5078 2725 418 2500 2740 9412 3983 1913 4078 5282 6517 3587 5580 5488 8876 6775 3141 5938 7295 3349 8880 9222 1183 1597 4639 3230 3419 2189 6320 2288 7778 1332 2626 3567 5259 2236 2271 5142 346 241 8271 9266 3343 3183 6590 9524 4611 9133 9402 4681 3454 2279 6823 5770 4677 2695 3167 6991 2387 955 4429 1564 1043 1278 4116 6085 9356 5961 2374 7324 3775 2080 5555 12 2826 1108 5450";
//	av[1] = "52 66 44 70 4 83 74 67 71 21 27 75 49 39 35 18 88 24 29 77 63 82 89 31 13 73 33 42 10 97 79 2 59 23 25 3 99 37 80 1 46 58 65 95 22 78 81 34 76 60 9 8 30 15 53 54 14 26 20 86 0 64 55 85 62 6 61 48 28 45 41 92 96 16 38 93 36 47 84 57 7 72 56 40 12 98 69 91 68 87 32 11 19 50 51 5";
//	av[1] = "70 80 47 26 0 62 14 83 45 10 90 65 76 2 11 40 51 94 27 73 87 82 44 95 58 6 25 5 23 61 32 29 36 28 92 18 15 12 34 55 37 71 56 97 86 67 16 43 3 30 91 7 60 35 50 69 17 85 21 31 41 93 54 74 1 64 33 81 24 72 88 57 38 46 48 53 75 77 42 9 49 79 96 39 20 13 66 22 98 68 52 78 63 89 99 59 8 84 19 4";
//	av[1] = "-3649 5522 -8314 -3981 -8254 -5169 -6550 -1398 7901 5269 -8554 719 5420 2107 -3087 6704 -4744 9985 8029 -5935 299 3474 -1726 7797 -1232 -1774 3368 1795 -3026 8932 4314 5511 5589 5149 7063 220 6227 980 2755 -9513 3123 -9070 6762 -7053 -8215 2912 1811 -6749 842 2062 -1964 840 -1617 -2470 5206 -8138 -3287 4897 8460 -3039 -7032 4499 -4255 -4559 -9006 -7405 3160 -6526 -3853 -2231 -3174 2854 2469 -2289 9621 -695 858 -3807 8021 9285 2852 -2405 2830 7633 6032 -5801 -4150 -4522 -8671 -8211 8293 -683 7650 -179 -8686 4434 7874 162 882 -9504";
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
			ac = tab_len(tab);
		}
		else
			tab_to_list(av, ac, &a);
		if (check_duplicates(a))
			exit_err(&a, 2);
		if (is_list_sorted(a))
			exit_err(&a, 0);
		set_pos(&a);
		printlst(&data, a, 'A');
		if (ac == 3)
			sort3(&a);
		else if (ac == 5)
        	sort5(&a, &b);
		else if (ac <= 200)
			insert_sort_chunk(&a, &b, 5);
		else
			insert_sort_chunk(&a, &b, 11);
//       printlst(&data, a, 'A');
//        printlst(&data, b, 'B');
//		exit_err(&a, 0);
	}
	return (0);
}