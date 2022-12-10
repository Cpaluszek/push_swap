/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:36 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/10 09:31:31 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack);

// For each value in array:
// Find the desired index after sort
int	*replace_by_index(int *origin, int count)
{
	int	*indexes;
	int	i;
	int	j;

	indexes = malloc(sizeof(int) * count);
	if (indexes == NULL)
	{
		ft_free(origin);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		indexes[i] = 0;
		j = 0;
		while (j < count)
		{
			if (i != j && origin[i] > origin[j])
				indexes[i]++;
			j++;
		}
		i++;
	}
	ft_free(origin);
	return (indexes);
}

void	init_stacks(t_data *data, int *values)
{
	int		i;
	t_stack	*new;

	data->stack_a = NULL;
	data->stack_b = NULL;
	i = data->value_count - 1;
	while (i >= 0)
	{
		new = ft_stacknew(values[i]);
		if (new == NULL)
		{
			free_data(data);
			break ;
		}
		ft_stack_push(&data->stack_a, new);
		i--;
	}
	ft_free(values);
}

void	free_data(t_data *data)
{
	free_stack(data->stack_a);
	free_stack(data->stack_b);
}

// Todo: move to stack directory
static void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		ft_free(stack);
		stack = next;
	}	
}
