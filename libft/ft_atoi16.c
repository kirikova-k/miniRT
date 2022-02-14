/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:09:34 by fbeatris          #+#    #+#             */
/*   Updated: 2021/10/16 21:11:32 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	get_digit(char c)
{
	int	max_digit;

	max_digit = 16 - 10 + 'A';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'A' && c <= 'F' && c <= max_digit)
		return (10 + c - 'A');
	else
		return (-1);
}

int	ft_atoi16(const char *str)
{
	unsigned long int	result;
	int					digit;

	result = 0;
	str += 2;
	digit = 1;
	while (digit >= 0 && *str != ' ' && *str)
	{
		digit = get_digit(ft_toupper(*str));
		result = result * 16;
		result = result + digit;
		++str;
	}
	return (result);
}
