/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:38:56 by fbeatris          #+#    #+#             */
/*   Updated: 2021/05/12 22:45:08 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		begin;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	i = 0;
	end = ft_strlen(s1) - 1;
	while (check_set(s1[begin], set))
		begin++;
	if (begin > end)
		return (ft_strdup(""));
	while (check_set(s1[end], set))
		end--;
	str = malloc(sizeof(*s1) * (end - begin + 2));
	if (!str)
		return (NULL);
	while (begin <= end)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}
