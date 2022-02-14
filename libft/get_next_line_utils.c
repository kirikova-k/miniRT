/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:09:23 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/05 20:30:02 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/errno.h>
#include "libft.h"

int	ft_strchr_n(const char *s, int c)
{
	size_t	i;
	char	*arr;
	char	cc;

	cc = c;
	arr = (char *)s;
	i = 0;
	if (s[0] == '\0')
		return (-1);
	while (arr[i] && arr[i] != cc)
		i++;
	if (arr[i] == cc)
		return (i);
	else
		return (-1);
}

char	*ft_substring(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	i;
	size_t	length;

	if (!s)
		return (NULL);
	i = start;
	length = 0;
	while (s[i++] && length < len)
		length++;
	if (length == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
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
