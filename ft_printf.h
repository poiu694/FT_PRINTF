/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangmlee <sangmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:55:51 by sangmlee          #+#    #+#             */
/*   Updated: 2022/01/10 18:58:46 by sangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *arg, ...);

char	*ft_transform_str_with_arg(va_list *ap, char ch);
char	*ft_transform_to_digit(int num);
char	*ft_transform_to_unsigned_int(unsigned int num, char op);
char	*ft_transform_to_char(char ch);
char	*ft_transform_to_str(char *str);
char	*ft_transform_to_unsigned_long(unsigned long address);

char	*ft_get_percent_index(char *str);
ssize_t	ft_process_printf_parse(va_list *ap, char *str);

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s);

int		ft_get_size(int n);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n, int is_lower, int nsize);
char	*ft_ultoa(unsigned long n, int nsize);

#endif
