/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:53:45 by nedogan           #+#    #+#             */
/*   Updated: 2025/09/30 13:53:46 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
