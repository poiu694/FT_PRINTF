/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:08:33 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/06 22:27:50 by sangmlee         ###   ########.fr       */
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

	if (n == 0)
		return (ft_strdup("0"));
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

char	*ft_uitoa(unsigned int n)
{
	int				size;
	unsigned int	temp;
	char			*ret;

	if (n == 0)
		return (ft_strdup("0"));
	temp = n;
	size = 0;
	while (temp)
	{
		temp /= 10;
		size = size + 1;
	}
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size] = '\0';
	while (--size >= 0)
	{
		ret[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (ret);
}

char	*ft_ultoa(unsigned long n)
{
	int				size;
	unsigned long	temp;
	char			*ret;

	if (n == 0)
		return (ft_strdup("0"));
	temp = n;
	size = 0;
	while (temp)
	{
		temp /= 10;
		size = size + 1;
	}
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size] = '\0';
	while (--size >= 0)
	{
		ret[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (ret);
}
