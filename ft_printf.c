/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:14:51 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/06 17:28:34 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_printf_parse(va_list ap, char *str)
{
	char	*format_str;
	char	*buf;
	int		state;

	state = 0;
	buf = "";
	while (*str)
	{
		if (state)
		{
			format_str = ft_transform_str_with_arg(ap, *(str++));
			if (format_str == NULL)
				return (NULL);
			ft_strlcat(buf, format_str, ft_strlen(format_str) + 1);
			state = 0;
		}
		else
		{
			if (*(str++) == '%')
				state = 1;
			else
				ft_strlcat(buf, str, 2);
		}
	}
	return (buf);
}

int	ft_printf(const char *arg, ...)
{
	ssize_t	read_size;
	char	*output_str;
	va_list	ap;

	read_size = -1;
	if (arg)
	{
		va_start(ap, arg);
		output_str = ft_process_printf_parse(ap, (char *)arg);
		if (output_str == NULL)
			return (read_size);
		read_size = write(1, output_str, ft_strlen(output_str));
		va_end(ap);
	}
	return ((int)read_size);
}
