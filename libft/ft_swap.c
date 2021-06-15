//
// Created by Stellar on 15/06/2021.
//

#include "include/libft.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
