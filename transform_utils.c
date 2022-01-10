/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:08:33 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/10 21:28:53 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_size(int n)
{
	int	ret;

	ret = 0;
	if (n <= 0)
		ret++;
	while (n != 0)
	{
		ret++;
		n = n / 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	char	*ret;

	if (n > 0)
		sign = 1;
	else
		sign = -1;
	size = ft_get_size(n);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size] = '\0';
	while (--size >= 0)
	{
		ret[size] = ((n % 10) * sign) + '0';
		n = n / 10;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}

char	*ft_get_base(int is_lower)
{
	if (is_lower)
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

char	*ft_uitoa(unsigned int n, int is_lower, int nsize)
{
	int				size;
	unsigned int	temp;
	char			*ret;
	char			*base;

	base = ft_get_base(is_lower);
	temp = n;
	size = 0;
	while (temp)
	{
		temp /= nsize;
		size = size + 1;
	}
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size--] = '\0';
	while (size >= 0)
	{
		ret[size] = base[n % nsize];
		n = n / nsize;
		size--;
	}
	return (ret);
}

char	*ft_ultoa(unsigned long n, int nsize)
{
	int				size;
	unsigned long	temp;
	char			*ret;

	temp = n;
	size = 2;
	while (temp)
	{
		temp /= nsize;
		size = size + 1;
	}
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size--] = '\0';
	while (size >= 2)
	{
		ret[size] = "0123456789abcdef"[n % nsize];
		n = n / nsize;
		size--;
	}
	ret[0] = '0';
	ret[1] = 'x';
	return (ret);
}
