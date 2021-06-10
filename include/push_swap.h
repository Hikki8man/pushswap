//
// Created by Johan Chevet on 5/28/21.
//

#ifndef PUSHSWAP_PUSH_SWAP_H
#define PUSHSWAP_PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct	s_lst
{
	int				nb;
	int 			pos;
	struct s_lst	*prev;
	struct s_lst	*next;
}t_lst;

typedef struct s_chunk
{
	int min;
	int max;
}t_chunk;

typedef struct	s_data
{
	int		a_size;
	int 	b_size;
}t_data;

//parsing
void parsing(int *ac, char **av, t_lst **a, t_lst **b);
int	str_int_cmp(char *s, int nb);
char	**str_to_tab(char *str);

//basic action
void	swap(t_lst *lst, char c, int silent);
void	rotate(t_lst **lst, char c, int silent);
void	rev_rotate(t_lst **lst, char c, int silent);
void	push(t_lst **a, t_lst **b, char c, int silent);

//lst function
t_lst	*new_elem(int nb);
void	add_back(t_lst **lst, t_lst *new);
t_lst 	*lst_cpy(t_lst *a);
t_lst	*lstlast(t_lst *lst);
int		lstsize(t_lst *lst);
void	freelst(t_lst **a);

//exit | error handling | free
void exit_err(t_lst **a, t_lst **b);

//sort
void    sort3(t_lst **a, int silent);
void 	sort5(t_lst **a, t_lst **b, int silent);
void	sort_chunk(t_lst **a, t_lst **b, int nb_chunks, int silent);

void	init_lst(t_lst **a, t_lst **b);
void set_pos(t_lst **a);
int is_list_sorted(t_lst *a);
t_chunk	*set_chunk(t_chunk *chunk, int size, int lstsize);
char 	compare_nb_moves(t_lst **a, int first, int sec);
int index_elem(t_lst *l, int pos);
void push_smallest_to_b(t_lst **a, t_lst **b, int smallest_pos, int silent);
void find_shortest_way_and_rotate(t_lst **l, int pos, char c, int silent);
int is_empty(t_lst **lst);
int find_biggest(t_lst **a);
int find_smallest(t_lst **a);



#endif //PUSHSWAP_PUSH_SWAP_H
