/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_sixty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:55:30 by nedogan           #+#    #+#             */
/*   Updated: 2025/09/30 13:55:31 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sort_up_to_sixty(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (stack_size(*a) > 3)
	{
		push_min_to_b(a, b);
		i++;
	}
	sort_three(a);
	while (i >= 0)
	{
		pa(a, b);
		i--;
	}
}
