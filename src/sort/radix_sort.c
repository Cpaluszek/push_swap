/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:19:15 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 11:27:10 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Todo: create a get_value method for cast simplification
char	*radix_sort(t_list **stack_a, t_list **stack_b, char *operations)
{
	int	size;
	int	max;
	int	max_index;
	int	i;
	int	j;

	(void) stack_b;
	get_max_index(stack_a, &max, &max_index);
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
