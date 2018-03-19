/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:49:02 by jkertgat          #+#    #+#             */
/*   Updated: 2018/03/19 00:07:29 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		sign;

	sign = n < 0 ? 1 : 0;
	if (n == -2147483648 || n == 0)
		return (n == 0 ? ft_strdup("0") : ft_strdup("-2147483648"));
	if (sign)
		n *= -1;
	i = ft_num_len(n);
	if (!(str = ft_strnew(i + 1 + sign)))
		return (NULL);
	str[i + sign] = '\0';
	while (--i >= sign)
	{
		str[i + sign] = (n % 10) + 48;
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
