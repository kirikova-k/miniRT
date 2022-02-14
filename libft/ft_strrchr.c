/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:42:24 by fbeatris          #+#    #+#             */
/*   Updated: 2021/05/10 23:13:33 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*arr;
	char	cc;

	cc = c;
	arr = (char *)s;
	i = 0;
	while (arr[i])
		i++;
	i++;
	while (i > 0)
	{
		if (arr[i - 1] == cc)
			return (&arr[i - 1]);
		else
			i--;
	}
	return (NULL);
}
