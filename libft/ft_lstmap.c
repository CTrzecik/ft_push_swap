/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dibranco <dibranco@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:08:43 by dibranco          #+#    #+#             */
/*   Updated: 2026/11/01 18:54:05 by dibranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nw_list;
	t_list	*tmp_list;

	if (!lst || !f || !del)
		return (NULL);
	nw_list = NULL;
	while (lst)
	{
		tmp_list = ft_lstnew(f(lst->content));
		if (!tmp_list)
		{
			ft_lstclear(&nw_list, del);
			break ;
		}
		ft_lstadd_back(&nw_list, tmp_list);
		lst = lst->next;
	}
	return (nw_list);
}
