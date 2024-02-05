/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:12:17 by tde-la-r          #+#    #+#             */
/*   Updated: 2023/11/07 18:05:47 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*area_dest;
	char	*area_src;

	if (!dest && !src && n)
		return (dest);
	i = 0;
	area_dest = dest;
	area_src = (void *)src;
	while (i < n)
	{
		area_dest[i] = area_src[i];
		i++;
	}
	return (dest);
}
