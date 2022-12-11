/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:06 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 11:40:41 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Todo: sort 2 ?
void	init_sort(t_data *data)
{
	char	*instructions;

	instructions = NULL;
	if (data->value_count == 3)
		instructions = sort_three(&data->stack_a, instructions);
	ft_printf("%s", instructions);
	ft_printf("------\n");
	print_stack(data->stack_a);
}
