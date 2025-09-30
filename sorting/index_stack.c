/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:55:19 by nedogan           #+#    #+#             */
/*   Updated: 2025/09/30 13:55:20 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*copy_stack_to_array(t_stack *a, int size)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_msg();
	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (arr);
}

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp_val;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp_val = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp_val;
			}
			j++;
		}
		i++;
	}
}

static int	*stack_to_array(t_stack *a, int size)
{
	int	*arr;

	arr = copy_stack_to_array(a, size);
	bubble_sort(arr, size);
	return (arr);
}

void	index_stack(t_stack *a, int size)
{
	int		*arr;
	t_stack	*tmp;
	int		i;

	arr = stack_to_array(a, size);
	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == arr[i])
			{
				tmp->value = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}
