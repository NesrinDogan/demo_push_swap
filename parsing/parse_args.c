#include "../push_swap.h"

static void	parse_validation(t_stack **a, char **arr, char *str)
{
	long	value;
	t_stack	*new_node;

	if (!is_number(str))
		clean_exit(*a, arr);
	value = ft_atol(str);
	if ((is_long(value)) && (value < -2147483648 || value > 2147483647))
		clean_exit(*a, arr);
	if (is_duplicate(*a, (int)value))
		clean_exit(*a, arr);
	new_node = stack_new((int)value);
	if (!new_node)
		clean_exit(*a, arr);
	stack_add_back(a, new_node);
}

static void	parse_and_add(t_stack **a, char *argv)
{
	int		j;
	char	**arr;

	arr = ft_split(argv, ' ');
	if (!arr)
		clean_exit(*a, arr);
	j = 0;
	while (arr[j])
	{
		parse_validation(a, arr, arr[j]);
		j++;
	}
	free_split(arr);
}

t_stack	*parse_args(int argc, char **argv)
{
	int		i;
	t_stack	*a;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		parse_and_add(&a, argv[i]);
		i++;
	}
	return (a);
}
