//
// Created by Johan Chevet on 6/9/21.
//

#include "../include/checker.h"

int main(int ac, char **av)
{
	int main(int ac, char **av)
	{
		t_lst *a;
		t_lst *b;
		char	**tab;

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
//		printlst(&data, a, 'A');
//		printf("%d\n", ac);
			if (ac == 3)
				sort3(&a);
			else if (ac == 5)
				sort5(&a, &b);
			else if (ac <= 200)
				insert_sort_chunk(&a, &b, 5);
			else
				insert_sort_chunk(&a, &b, 11);
		}
		return (0);
	}
}