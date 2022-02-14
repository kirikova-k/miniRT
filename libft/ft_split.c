/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:19:23 by fbeatris          #+#    #+#             */
/*   Updated: 2021/04/16 21:19:26 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static void	free_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	count_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static char	**create_arr(char *str, char **arr, char c, int count)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	j = 0;
	s = 0;
	while (i < count)
	{
		arr[i] = malloc(sizeof(*str) * (count_len(&str[s], c) + 1));
		if (!arr[i])
			free_mem(arr);
		while (str[s] && str[s] != c)
			arr[i][j++] = str[s++];
		arr[i][j] = '\0';
		while (str[s] && str[s] == c)
			s++;
		j = 0;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		b;
	int		count;
	char	**arr;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	b = 0;
	count = count_words(str, c);
	while (str[b] && str[b] == c)
		b++;
	arr = malloc(sizeof(*arr) * (count + 1));
	if (!arr)
		return (NULL);
	arr = create_arr(&str[b], arr, c, count);
	return (arr);
}
