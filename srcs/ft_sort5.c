//
// Created by Johan Chevet on 6/10/21.
//

#include "../include/push_swap.h"

void	sort5(t_lst **a, t_lst **b, int silent)
{
	push_smallest_to_b(a, b, index_elem(*a, find_smallest(a)), silent);
	push_smallest_to_b(a, b, index_elem(*a, find_smallest(a)), silent);
	sort3(a, silent);
	push(b, a, 'a', silent);
	push(b, a, 'a', silent);
}
