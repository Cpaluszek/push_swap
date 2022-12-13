/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:19:15 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 14:32:43 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_stack_b(t_list **st_a, t_list **stack_b);

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	while (!is_sorted(*stack_a))
	{
		size = ft_lstsize(*stack_a);
		j = -1;
		while (++j < size)
		{
			if ((get_lst_int_value(*stack_a) >> i) & 1)
			{
				rotate_stack(stack_a);
				ft_printf("ra\n");
			}
			else
			{
				push_to_stack(stack_a, stack_b);
				ft_printf("pb\n");
			}
		}
		clear_stack_b(stack_a, stack_b);
		i++;
	}
}

static void	clear_stack_b(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b))
	{
		push_to_stack(stack_b, stack_a);
		ft_printf("pa\n");
	}
}
