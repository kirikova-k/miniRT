/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:43:19 by fbeatris          #+#    #+#             */
/*   Updated: 2021/04/25 18:33:41 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	else
	{
		while (i < count * size)
		{
			arr[i] = 0;
			i++;
		}
	}
	return (arr);
}
