/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 23:37:47 by fbeatris          #+#    #+#             */
/*   Updated: 2021/05/08 22:53:56 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_to_file(int n, int fd)
{
	char	c;

	if (n != 0)
	{
		put_to_file(n / 10, fd);
		c = '0' + (n % 10);
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{	
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		put_to_file(-n, fd);
	}
	else if (n == 0)
		write(fd, "0", 1);
	else
		put_to_file(n, fd);
}
