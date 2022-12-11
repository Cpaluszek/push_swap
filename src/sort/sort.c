/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:06 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 13:16:29 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Todo: sort 2 ?
void	init_sort(t_data *data)
{
	char	*operations;

	operations = NULL;
	if (data->value_count == 3)
		operations = sort_three(&data->stack_a, operations);
	if (data->value_count == 5)
		operations = sort_five(&data->stack_a, &data->stack_b, operations);
	ft_printf("%s", operations);
	ft_printf("------\n");
	print_stacks(data);
}
