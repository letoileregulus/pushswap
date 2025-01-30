/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:45:51 by agokcek           #+#    #+#             */
/*   Updated: 2024/11/13 16:18:18 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_counter(int n)
{
	unsigned int	d;

	d = 0;
	if (n <= 0)
		d++;
	while (n)
	{
		n /= 10;
		++d;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	unsigned int	dig;
	char			*str;
	const char		*num;

	num = "0123456789";
	dig = digit_counter(n);
	str = ft_calloc(dig + 1, sizeof(char));
	if (str == 0)
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[--dig] = num[n % 10];
		else
			str[--dig] = num[(n % 10) * -1];
		n /= 10;
	}
	return (str);
}
