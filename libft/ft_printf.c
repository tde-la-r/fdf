/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:21:36 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/10 18:00:51 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_argument(va_list *list, const char **arg, int *count)
{
	(*arg)++;
	if (**arg == 'i' || **arg == 'd' || **arg == 'c')
		print_integer_ptf(list, arg, count);
	else if (**arg == 'u' || **arg == 'x' || **arg == 'X')
		print_u_int_ptf(list, arg, count);
	else if (**arg == 'p')
		print_pointer_ptf(list, count);
	else if (**arg == 's')
		print_string_ptf(list, count);
	else if (**arg == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else if (**arg)
	{
		write(1, "%", 1);
		write(1, *arg, 1);
		*count += 2;
	}
	else
		return (0);
	return (1);
}

int	ft_printf(const char *to_print, ...)
{
	va_list	list;
	int		count;

	if (!to_print)
		return (-1);
	count = 0;
	va_start(list, to_print);
	while (*to_print)
	{
		if (*to_print != '%')
		{
			write(1, to_print, 1);
			count++;
		}
		else
		{
			if (!print_argument(&list, &to_print, &count))
				return (-1);
		}
		to_print++;
	}
	va_end(list);
	return (count);
}
