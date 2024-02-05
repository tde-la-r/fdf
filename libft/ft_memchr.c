/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:39:26 by tde-la-r          #+#    #+#             */
/*   Updated: 2023/11/02 14:33:26 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*area;

	area = (char *) s;
	i = 0;
	while (i < n)
	{
		if (area[i] == (char) c)
			return (area + i);
		i++;
	}
	return (NULL);
}
