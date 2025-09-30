/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:55:24 by nedogan           #+#    #+#             */
/*   Updated: 2025/09/30 13:55:25 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	process_bit(t_stack **a, t_stack **b, int i, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((*a)->value >> i) & 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;

	size = stack_size(*a);
	index_stack(*a, size);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		process_bit(a, b, i, size);
		i++;
	}
}
