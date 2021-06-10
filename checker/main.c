//
// Created by Johan Chevet on 6/9/21.
//

#include "../include/checker.h"

static void	ss(t_lst **a, t_lst **b)
{
	swap(*a, 'a', 1);
	swap(*b, 'b', 1);
}

static void	read_entry_part_2(t_lst **a, t_lst **b, char **line)
{
	if (!ft_strncmp(*line, "pb", ft_strlen(*line)))
		push(a, b, 'b', 1);
	else if (!ft_strncmp(*line, "ra", ft_strlen(*line)))
		rotate(a, 'a', 1);
	else if (!ft_strncmp(*line, "rb", ft_strlen(*line)))
		rotate(b, 'b', 1);
	else if (!ft_strncmp(*line, "rr", ft_strlen(*line)))
	{
		rotate(a, 'a', 1);
		rotate(b, 'b', 1);
	}
	else if (!ft_strncmp(*line, "rra", ft_strlen(*line)))
		rev_rotate(a, 'a', 1);
	else if (!ft_strncmp(*line, "rrb", ft_strlen(*line)))
		rev_rotate(b, 'b', 1);
	else if (!ft_strncmp(*line, "rrr", ft_strlen(*line)))
	{
		rev_rotate(a, 'a', 1);
		rev_rotate(b, 'b', 1);
	}
	else
	{
		free(*line);
		exit_err(a, b);
	}
}

static void	read_entry(t_lst **a, t_lst **b)
{
	char	*line;
	int		ret;

	line = NULL;
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == -1 || (!*line && ret == 1))
			exit_err(a, b);
		if (ret == 0)
			break ;
		if (!ft_strncmp(line, "sa", ft_strlen(line)))
			swap(*a, 'a', 1);
		else if (!ft_strncmp(line, "sb", ft_strlen(line)))
			swap(*b, 'b', 1);
		else if (!ft_strncmp(line, "ss", ft_strlen(line)))
			ss(a, b);
		else if (!ft_strncmp(line, "pa", ft_strlen(line)))
			push(b, a, 'a', 1);
		else
			read_entry_part_2(a, b, &line);
		free(line);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;

	parsing(&ac, av, &a, &b);
	read_entry(&a, &b);
	if (is_list_sorted(a) == 1)
		ft_putstr("OK");
	else
		ft_putstr("KO");
	freelst(&a);
	freelst(&b);
	return (0);
}
