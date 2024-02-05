/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:53:55 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/16 18:07:21 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_base(char *base_l, char *base_u)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		base_l[i] = '0' + i;
		base_u[i] = '0' + i;
		i++;
	}
	j = 0;
	while (j < 6)
	{
		base_l[i + j] = 'a' + j;
		base_u[i + j] = 'A' + j;
		j++;
	}
}

bool	ft_isbase(int c, int base_len)
{
	char	base_l[16];
	char	base_u[16];
	int		i;

	i = 0;
	init_base(base_l, base_u);
	while (i < base_len && i < 16)
	{
		if (c == base_l[i] || c == base_u[i])
			return (true);
		i++;
	}
	return (false);
}
