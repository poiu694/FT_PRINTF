/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:14:51 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/10 10:54:23 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_percent_index(char *str)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == '%')
			break ;
		str++;
	}
	return (str);
}

ssize_t	ft_process_printf_parse(va_list *ap, char *str)
{
	char	*format_str;
	char	*percent_index;
	ssize_t	read_size;

	read_size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			format_str = ft_transform_str_with_arg(ap, *(++str));
			if (format_str == NULL)
				return (-1);
			read_size += write(1, format_str, ft_strlen(format_str));
			free(format_str);
			str++;
		}
		else
		{
			percent_index = ft_get_percent_index(str);
			read_size += write(1, str, (percent_index - str));
			str = str + (percent_index - str);
		}
	}
	return (read_size);
}

int	ft_printf(const char *arg, ...)
{
	ssize_t	read_size;
	va_list	ap;

	read_size = -1;
	if (arg)
	{
		va_start(ap, arg);
		read_size = ft_process_printf_parse(&ap, (char *)arg);
		va_end(ap);
	}
	return ((int)read_size);
}
