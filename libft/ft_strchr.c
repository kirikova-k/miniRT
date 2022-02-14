/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 22:42:24 by fbeatris          #+#    #+#             */
/*   Updated: 2021/05/10 23:13:13 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*arr;
	char	cc;

	cc = c;
	arr = (char *)s;
	i = 0;
	while (arr[i] && arr[i] != cc)
		i++;
	if (arr[i] == cc)
		return (&arr[i]);
	else
		return (NULL);
}
