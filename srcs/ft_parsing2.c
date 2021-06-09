//
// Created by Stellar on 09/06/2021.
//

#include "../include/push_swap.h"

void	init_lst(t_lst **a, t_lst **b)
{
	*a = NULL;
	*b = NULL;
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

char	**str_to_tab(char *str)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (tab == NULL)
		exit(1);
	return (tab);
}
