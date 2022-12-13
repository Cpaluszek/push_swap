/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:43:18 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 10:24:00 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*push_lowest(t_list **stack_a, t_list **stack_b, char *operations);

char	*sort_five(t_list **stack_a, t_list **stack_b, char *operations)
{
	operations = push_lowest(stack_a, stack_b, operations);
	operations = push_lowest(stack_a, stack_b, operations);
	if (!is_sorted(*stack_a))
		operations = sort_three(stack_a, operations);
	push_to_stack(stack_b, stack_a);
	push_to_stack(stack_b, stack_a);
	operations = ft_strjoin(operations, "pa\npa\n");
	return (operations);
}

static char	*push_lowest(t_list **stack_a, t_list **stack_b, char *operations)
{
	int		index;
	int		min;

	get_min_index(stack_a, &min, &index);
	while (*(int *)(*stack_a)->content != min)
	{
		if (index - (ft_lstsize(*stack_a) / 2) > 0)
		{
			operations = ft_strjoin(operations, "rra\n");
			rev_rotate_stack(stack_a);
		}
		else
		{
			operations = ft_strjoin(operations, "ra\n");
			rotate_stack(stack_a);
		}
	}
	push_to_stack(stack_a, stack_b);
	operations = ft_strjoin(operations, "pb\n");
	return (operations);
}
