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
void	swap(t_lst *lst, char c);
void	rotate(t_lst **lst, char c);
void	rev_rotate(t_lst **lst, char c);
void	push(t_lst **a, t_lst **b, char c);

//lst function
t_lst	*new_elem(int nb);
void	add_back(t_lst **lst, t_lst *new);
t_lst 	*lst_cpy(t_lst *a);
t_lst	*lstlast(t_lst *lst);
int		lstsize(t_lst *lst);
void	freelst(t_lst **a);

//error handling
void exit_err(t_lst **a, int err);

void	init_lst(t_lst **a, t_lst **b);
void set_pos(t_lst **a);
int is_list_sorted(t_lst *a);
int is_empty(t_lst **lst);


#endif //PUSHSWAP_PUSH_SWAP_H
