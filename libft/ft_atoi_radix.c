/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <tde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:28:30 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/16 18:08:22 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_before_number(const char *nptr, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_radix(const char *nptr, int base)
{
	int		sign;
	int		number;
	int		i;

	i = read_before_number(nptr, &sign);
	number = 0;
	while (ft_isbase(nptr[i], base))
	{
		number *= base;
		if (ft_isdigit(nptr[i]))
			number += nptr[i] - '0';
		else if (ft_islower(nptr[i]))
			number += nptr[i] - 'a' + 10;
		else
			number += nptr[i] - 'A' + 10;
		i++;
	}
	return (number * sign);
}
