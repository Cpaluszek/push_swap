/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:56:18 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 12:35:41 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_list *stack);

void	print_array(int	*array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("%d\n", array[i]);
		i++;
	}
}

void	print_stacks(t_data *data)
{
	printf("[A]\n");
	print_stack(data->stack_a);
	printf("[B]\n");
	print_stack(data->stack_b);
}

static void	print_stack(t_list *stack)
{
	printf("> ");
	while (stack)
	{
		printf("%d", get_lst_int_value(stack));
		stack = stack->next;
		if (stack)
			printf("->");
	}
	printf("\n");
}

// void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d\n", stack->value);
// 		stack = stack->next;
// 	}
// }
