//
// Created by Johan Chevet on 5/28/21.
//

#ifndef PUSHSWAP_PUSH_SWAP_H
#define PUSHSWAP_PUSH_SWAP_H

#include "libft/libft.h"
#include "stdio.h"

typedef struct	s_lst
{
	int				nb;
	struct s_lst	*prev;
	struct s_lst	*next;
}t_lst;

typedef struct	s_data
{
	int		a_size;
	int 	b_size;
}t_data;

#endif //PUSHSWAP_PUSH_SWAP_H
