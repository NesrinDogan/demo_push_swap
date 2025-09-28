#include "../push_swap.h"

void	error_msg(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	clean_exit(t_stack *a, char **arr)
{
	if (arr)
		free_split(arr);
	if (a)
		free_stack(&a);
	error_msg();
}
