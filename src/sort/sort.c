/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:06 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 14:41:13 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort(t_data *data)
{
	if (data->value_count == 2)
		ft_printf("sa\n");
	else if (data->value_count == 3)
		sort_three(&data->stack_a);
	else if (data->value_count == 5)
		sort_five(&data->stack_a, &data->stack_b);
	else
		radix_sort(&data->stack_a, &data->stack_b);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (get_lst_int_value(stack) > get_lst_int_value(stack->next))
			return (0);
		stack = stack->next;
	}
	return (1);
}
