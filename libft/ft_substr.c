/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:32:57 by fbeatris          #+#    #+#             */
/*   Updated: 2021/05/10 23:15:44 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	i;
	size_t	length;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = start;
	length = 0;
	while (s[i++] && length < len)
		length++;
	subst = malloc(sizeof(*s) * (length + 1));
	if (!subst)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		subst[i] = s[start + i];
		i++;
	}
	subst[i] = '\0';
	return (subst);
}
