/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:19:15 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 12:56:19 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*radix_sort(t_list **stack_a, t_list **stack_b, char *operations)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	while (!is_sorted(*stack_a))
	{
		size = ft_lstsize(*stack_a);
		j = 0;
		while (j < size)
		{
			if ((get_lst_int_value(*stack_a) >> i) & 1)
			{
				rotate_stack(stack_a);
				operations = ft_strjoin(operations, "ra\n");
			}
			else
			{
				push_to_stack(stack_a, stack_b);
				operations = ft_strjoin(operations, "pb\n");
			}
			j++;
		}
		while (ft_lstsize(*stack_b))
		{
			push_to_stack(stack_b, stack_a);
			operations = ft_strjoin(operations, "pa\n");
		}
		i++;
	}
	return (operations);
}
