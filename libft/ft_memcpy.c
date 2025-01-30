/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:12:01 by agokcek           #+#    #+#             */
/*   Updated: 2024/11/13 11:12:24 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*x;
	const unsigned char	*y;

	x = (unsigned char *)dst;
	y = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (n > i)
	{
		x[i] = y[i];
		i++;
	}
	return (dst);
}
