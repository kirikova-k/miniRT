/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:35:10 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 15:14:42 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

int	exit_hook(int key_code, t_data *data)
{
	(void)key_code;
	(void)data;
	ft_putstr_fd("Exit\n", 1);
	exit(0);
}
