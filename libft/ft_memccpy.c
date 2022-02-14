/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:18:56 by fbeatris          #+#    #+#             */
/*   Updated: 2021/04/16 21:19:02 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned char	cc;
	size_t			i;

	if (!destination && !source)
		return (NULL);
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == cc)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
