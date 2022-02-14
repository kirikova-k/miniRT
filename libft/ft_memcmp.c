/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:52:12 by fbeatris          #+#    #+#             */
/*   Updated: 2021/04/21 23:27:37 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;
	int				res;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	res = 0;
	while (i < n && res == 0)
	{
		res = st1[i] - st2[i];
		i++;
	}
	return (res);
}
