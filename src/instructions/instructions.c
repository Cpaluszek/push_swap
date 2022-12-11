/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:36:44 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 09:45:18 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Note: protect functions ?

// Send top of src stack to top of dst
void	push_to_stack(t_list **src, t_list **dst)
{
	t_list	*temp;

	temp = *src;
	ft_lstadd_front(dst, *src);
	*src = temp;
}

// Swap to numbers at the top of src
// NOTE: swap function in libft
void	swap_stack(t_list **src)
{
	t_list	*elem;
	void	*tmp;

	elem = *src;
	tmp = elem->next->content;
	elem->next->content = elem->content;
	elem->content = tmp;
}

// Top of the stack goes to bottom
// Note: find last function ?
void	rotate_stack(t_list **src)
{
	t_list	*elem;
	t_list	*first;

	elem = *src;
	first = (*src)->next;
	while (elem && elem->next)
		elem = elem->next;
	elem->next = *src;
	elem->next->next = NULL;
	*src = first;
}

// Bottom of the stack goes to top
void	rev_rotate_stack(t_list **src)
{
	t_list	*last;
	t_list	*prev;

	last = *src;
	while (last && last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *src;
	*src = last;
}
