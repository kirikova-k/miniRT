/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:31:16 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/05 20:29:20 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lets_free(char **target)
{
	if (*target != NULL)
	{
		free(*target);
		*target = NULL;
	}
}

char	*join(char **s1, char *s2)
{
	char	*res;

	if (*s1)
		res = ft_strjoin(*s1, s2);
	else
		res = ft_strdup(s2);
	lets_free(s1);
	return (res);
}

int	finish_him(int size, int place, char **current)
{
	if (size == 0 && place == -1)
	{
		lets_free(current);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*current = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			size;
	int			place;
	char		*temp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	size = 1;
	place = -1;
	while (size != 0 && place == -1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		buf[size] = '\0';
		current = join(&current, buf);
		if (current)
			place = ft_strchr_n(current, 10);
	}
	*line = ft_substring(current, 0, place);
	temp = current;
	current = ft_substring(current, place + 1, ft_strlen(current) - place);
	lets_free(&temp);
	return (finish_him(size, place, &current));
}
