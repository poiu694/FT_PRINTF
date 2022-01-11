/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:27:23 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/11 09:56:14 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_transform_str_with_arg(va_list *ap, char ch, ssize_t *zero_cnt)
{
	if (ch == 'd' || ch == 'i')
		return (ft_transform_to_digit(va_arg(*ap, int)));
	if (ch == 'u' || ch == 'x' || ch == 'X')
		return (ft_transform_to_unsigned_int(va_arg(*ap, unsigned int), ch));
	if (ch == 's')
		return (ft_transform_to_str(va_arg(*ap, char *)));
	if (ch == 'c')
		return (ft_transform_to_char((char)va_arg(*ap, int), zero_cnt));
	if (ch == 'p')
		return (ft_transform_to_unsigned_long(va_arg(*ap, unsigned long)));
	if (ch == '%')
		return (ft_strdup("%"));
	return (NULL);
}
