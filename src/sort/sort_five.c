/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:43:18 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/12 13:25:20 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*push_lowest(t_list **stack_a, t_list **stack_b, char *operations);

// Note: push smallest values to stack b?
char	*sort_five(t_list **stack_a, t_list **stack_b, char *operations)
{
	// Push smallest to B
	operations = push_lowest(stack_a, stack_b, operations);
	operations = push_lowest(stack_a, stack_b, operations);
	operations = sort_three(stack_a, operations);
	push_to_stack(stack_b, stack_a);
	push_to_stack(stack_b, stack_a);
	operations = ft_strjoin(operations, "pa\npa\n");
	return (operations);
}

static char *push_lowest(t_list **stack_a, t_list **stack_b, char *operations)
{
	int		index;
	int		min;

	get_lowest_index(stack_a, &min, &index);
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

void	get_lowest_index(t_list **stack, int *min, int *index)
{
	int		i;
	t_list	*st;

	i = 0;
	*index = 0;
	st = *stack;
	*min = *(int *)st->content;
	while (st)
	{
		if (*(int *)st->content < *min)
		{
			*min = *(int *)st->content;
			*index = i;
		}
		st = st->next;
		i++;
	}
}