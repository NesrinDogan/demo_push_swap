#include "../push_swap.h"

static int	find_min_pos(t_stack *a)
{
	int		min;
	int		pos;
	int		i;
	t_stack	*tmp;

	if (!a)
		return (-1);
	min = a->value;
	pos = 0;
	i = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	pos = find_min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
	pb(a, b);
}

void	sort_up_to_six(t_stack **a, t_stack **b)
{
	if (stack_size(*a) < 5)
	{
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
	}
	else if (stack_size(*a) == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
	else
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
		pa(a, b);
	}
}
