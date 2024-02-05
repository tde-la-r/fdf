/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:01:59 by tde-la-r          #+#    #+#             */
/*   Updated: 2023/11/07 19:03:57 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;

	if (!nmemb || !size)
	{
		memory = malloc(0);
		if (!memory)
			return (NULL);
		return (memory);
	}
	if (nmemb >= 2147483647 || size >= 2147483647)
		return (NULL);
	if (nmemb * size > 2147483647)
		return (NULL);
	memory = malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, nmemb * size);
	return (memory);
}
