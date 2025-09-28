/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedogan <nedogan@42istanbul.student.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:02 by nedogan           #+#    #+#             */
/*   Updated: 2025/08/19 12:32:13 by nedogan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int nbr);

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	long	nbr;

	len = num_len(n);
	nbr = n;
	result = malloc(len + 1);
	if (!result)
	{
		return (NULL);
	}
	result[len] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		result[0] = '0';
	while (nbr != 0)
	{
		result[--len] = ((nbr % 10) + '0');
		nbr = nbr / 10;
	}
	return (result);
}

static int	num_len(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
