/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 23:15:37 by fbeatris          #+#    #+#             */
/*   Updated: 2021/05/10 23:24:45 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*n;

	str = (char *)haystack;
	n = (char *)needle;
	if (ft_strlen(n) == 0 || haystack == needle)
		return (str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (n[j] && n[j] == str[i + j] && i + j < len)
			j++;
		if (n[j] == '\0')
			return (&str[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
