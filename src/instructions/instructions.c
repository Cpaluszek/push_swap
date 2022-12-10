/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:36:44 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/10 11:44:27 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Send top of src stack to top of dst
void	push_to_stack(t_stack **src, t_stack **dst)
{
	t_stack	*temp;

	temp = *src;
	ft_stack_push(dst, *src);
	*src = temp;
}

// Swap to numbers at the top of src
// NOTE: swap function in libft
void	swap_stack(t_stack **src)
{
	t_stack	*elem;
	int		tmp;

	elem = *src;
	tmp = elem->next->value;
	elem->next->value = elem->value;
	elem->value = tmp;
}

// Top of the stack goes to bottom
// Note: find last function ?
void	rotate_stack(t_stack **src)
{
	t_stack	*elem;
	t_stack *first;
	
	elem = *src;
	first = *src;
	while (elem && elem->next)
		elem = elem->next;
	elem->next = first;
	elem->next->next = NULL;
}

// Bottom of the stack goes to top
void	rev_rotate_stack(t_stack **src)
{
	t_stack *elem;
	t_stack *prev;

	elem = *src;
	while (elem && elem->next)
	{
		prev = elem;
		elem = elem->next;
	}
	prev->next = NULL;
	elem->next = *src;
}
