/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:28:55 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/07 23:14:47 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_transform_to_digit(int num)
{
	if (num == 0)
		return ("0");
	return (ft_itoa(num));
}

char	*ft_transform_to_unsigned_int(unsigned int num)
{
	if (num == 0)
		return ("0");
	return (ft_uitoa(num));
}

char	*ft_transform_to_char(char ch)
{
	char	*ret;

	ret = &ch;
	return (ret);
}

char	*ft_transform_to_str(char *str)
{
	if (!str)
		return ("(null)");
	return (str);
}

char	*ft_transform_to_unsigned_long(unsigned long address)
{
	if (address == 0)
		return ("0x0");
	return (ft_ultoa(address));
}
