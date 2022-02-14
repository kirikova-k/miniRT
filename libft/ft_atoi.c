/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:44:46 by fbeatris          #+#    #+#             */
/*   Updated: 2021/10/16 16:42:43 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	choose_number(const char *str, int sign)
{
	unsigned long long int	num;
	int						i;

	num = 0;
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if (sign == -1 && num > 9223372036854775807)
		return (0);
	if (num > 9223372036854775807)
		return (-1);
	return (num);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (sign * choose_number(&str[i], sign));
	else
		return (0);
}
