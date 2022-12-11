/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:43:18 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 12:55:17 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sort_five(t_list **stack_a, t_list **stack_b, char *operations)
{
	char	*temp;

	push_to_stack(stack_a, stack_b);
	push_to_stack(stack_a, stack_b);
	temp = ft_strjoin(operations, "pb\npb\n");
	free(operations);
	return (temp);
}