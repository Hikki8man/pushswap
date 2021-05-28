/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchevet <jchevet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:51:00 by jchevet           #+#    #+#             */
/*   Updated: 2020/12/19 17:51:00 by jchevet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ulllength(unsigned long long int n, int base_len)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_ullitoa_base(unsigned long long int n, char *base)
{
	char	*to_ret;
	int		size;
	int		base_len;

	base_len = ft_strlen(base);
	size = ft_ulllength(n, base_len);
	to_ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!to_ret)
		return (NULL);
	to_ret[size] = '\0';
	while (--size >= 0)
	{
		to_ret[size] = base[n % base_len];
		n /= base_len;
	}
	return (to_ret);
}
