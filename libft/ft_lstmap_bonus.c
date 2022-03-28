/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:29:34 by hhamdy            #+#    #+#             */
/*   Updated: 2021/12/20 12:00:24 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*buff;
	t_list	*tmp;

	tmp = NULL;
	buff = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&buff, del);
			return (NULL);
		}
		ft_lstadd_back(&buff, tmp);
		lst = lst->next;
	}
	return (buff);
}
