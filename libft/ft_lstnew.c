/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:08:52 by fbeatris          #+#    #+#             */
/*   Updated: 2021/10/16 19:08:53 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*aa;

	aa = (t_list *)malloc(sizeof (*aa));
	if (!aa)
		return (NULL);
	aa->content = content;
	aa->next = NULL;
	return (aa);
}
