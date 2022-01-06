/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:28:55 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/06 17:31:15 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
char	*ft_transform_to_digit(int num)
{
	printf("num : %d\n", num);
	return (NULL);
}

char	*ft_transform_to_unsigned_int(unsigned int num)
{
	printf("num : %u\n", num);
	return (NULL);

}

char	*ft_transform_to_string(char *str)
{
	printf("num : %s\n", str);
	return (NULL);

}

char	*ft_transform_to_char(char ch)
{
	printf("num : %c\n", ch);
	return (NULL);

}

char	*ft_transform_to_unsigned_long(unsigned long address)
{
	printf("num : %lu\n", address);
	return (NULL);

}
