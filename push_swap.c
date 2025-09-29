#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		return (0);
	b = NULL;
	a = parse_args(argc, argv);
	size = stack_size(a);
	if (size < 2 || is_sorted(a))
		return (0);
	if (size == 2)
		sa(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size <= 59)
		sort_up_to_sixty(&a, &b);
	else
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

