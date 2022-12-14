/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:43:18 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 14:35:43 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_lowest(t_list **stack_a, t_list **stack_b);

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_lowest(stack_a, stack_b);
	push_lowest(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	push_to_stack(stack_b, stack_a);
	ft_printf("pa\n");
	push_to_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

static void	push_lowest(t_list **stack_a, t_list **stack_b)
{
	int		index;
	int		min;

	get_min_index(stack_a, &min, &index);
	while (get_lst_int_value(*stack_a) != min)
	{
		if (index - (ft_lstsize(*stack_a) / 2) > 0)
		{
			ft_printf("rra\n");
			rev_rotate_stack(stack_a);
		}
		else
		{
			ft_printf("ra\n");
			rotate_stack(stack_a);
		}
	}
	push_to_stack(stack_a, stack_b);
	ft_printf("pb\n");
}
