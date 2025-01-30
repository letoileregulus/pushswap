/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agokcek <agokcek@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:34:18 by agokcek           #+#    #+#             */
/*   Updated: 2024/11/13 14:56:26 by agokcek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	return (dst);
}
