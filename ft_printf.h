/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:55:51 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/04 17:05:38 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *arg, ...);

char	*ft_transform_str_with_arg(va_list ap, char ch);
char	*ft_transform_to_digit(int num);
char	*ft_transform_to_unsigned_int(unsigned int num);
char	*ft_transform_to_string(char *str);
char	*ft_transform_to_char(char ch);
char	*ft_transform_to_unsigned_long(unsigned long address);

char	*ft_process_printf_parse(va_list ap, char *str);

size_t	ft_strlen(char *str);
char	*ft_strlcat(char *s1, char *s2, size_t len);

#endif
