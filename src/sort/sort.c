/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:06 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 11:28:40 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Todo: sort 2
void	init_sort(t_data *data)
{
	char	*operations;

	operations = NULL;
	if (data->value_count == 2)
		operations = "sa\n";
	else if (data->value_count == 3)
		operations = sort_three(&data->stack_a, operations);
	else if (data->value_count == 5)
		operations = sort_five(&data->stack_a, &data->stack_b, operations);
	else
		operations = radix_sort(&data->stack_a, &data->stack_b, operations);
	ft_printf("%s", operations);
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
