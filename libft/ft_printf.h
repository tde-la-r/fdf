/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:16:23 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/10 18:01:41 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *to_print, ...);
void		print_pointer_ptf(va_list *list, int *count);
void		print_u_int_ptf(va_list *list, const char **to_print, int *count);
void		print_integer_ptf(va_list *list, const char **to_print, int *count);
void		print_string_ptf(va_list *list, int *count);
void		ft_putnbr_ptf(int n, unsigned long u, char *base, int *count);
size_t		ft_strlen(const char *s);

#endif
