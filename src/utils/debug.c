/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:56:18 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 09:40:17 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", *(int *)(stack->content));
		stack = stack->next;
	}
}

// void	print_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d\n", stack->value);
// 		stack = stack->next;
// 	}
// }
