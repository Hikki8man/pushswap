//
// Created by Johan Chevet on 5/28/21.
//
#include "../include/push_swap.h"

void printlst(t_lst *lst, char c)
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

void find_shortest_way_and_rotate(t_lst **l, int pos, char c)
{
	int	size;
	int index;

	size = lstsize(*l);
	index = index_elem(*l, pos);
	if (index <= size / 2 + size % 2)
		while ((*l)->pos != pos)
			rotate(l, c);
	else
	{
		while ((*l)->pos != pos)
			rev_rotate(l, c);
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
				find_shortest_way_and_rotate(a, hold_first, 'a');
			else
				find_shortest_way_and_rotate(a, hold_second, 'a');
			push(a, b, 'b');
		}
	}

	while (*b)
	{
		find_shortest_way_and_rotate(b, find_biggest(b), 'b');
		push(b, a, 'a');
	}
}



int main(int ac, char **av)
{
	t_lst *a;
	t_lst *b;

	ac = 2;
	av[1] = "5 23 2 1 -3";
	parsing(&ac, av, &a, &b);
	if (ac == 3)
		sort3(&a);
	else if (ac == 5)
    	sort5(&a, &b);
	else if (ac <= 200)
		insert_sort_chunk(&a, &b, 5);
	else
		insert_sort_chunk(&a, &b, 11);
   printlst(a, 'A');
//    printlst(&data, b, 'B');
//	exit_err(&a, 0);//TODO free when done
	return (0);
}