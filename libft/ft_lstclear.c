/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbeatris <fbeatris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:08:40 by fbeatris          #+#    #+#             */
/*   Updated: 2021/10/16 19:08:40 by fbeatris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new_adr;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		new_adr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new_adr;
	}
}
