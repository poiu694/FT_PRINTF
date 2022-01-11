/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:28:55 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/11 14:11:08 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_transform_to_digit(int num)
{
	if (num == 0)
		return (ft_strdup("0"));
	return (ft_itoa(num));
}

char	*ft_transform_to_unsigned_int(unsigned int num, char op)
{
	if (num == 0)
		return (ft_strdup("0"));
	if (op == 'x')
		return (ft_uitoa(num, 1, 16));
	if (op == 'X')
		return (ft_uitoa(num, 0, 16));
	if (op == 'u')
		return (ft_uitoa(num, 1, 10));
	return (ft_strdup(""));
}

char	*ft_transform_to_char(char ch, ssize_t *zero_cnt)
{
	char	*ret;

	if (!ch)
	{
		*zero_cnt = *zero_cnt + 1;
		write(1, &ch, 1);
	}
	ret = (char *)malloc(sizeof(char) + 1);
	ret[0] = ch;
	ret[1] = '\0';
	return (ret);
}

char	*ft_transform_to_str(char *str)
{
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*ft_transform_to_unsigned_long(unsigned long address)
{
	if (address == 0)
		return (ft_strdup("0x0"));
	return (ft_ultoa(address, 16));
}
