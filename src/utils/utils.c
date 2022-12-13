/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:36 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 11:26:35 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_lst_int_value(t_list *stack)
{
	return (*(int *)stack->content);
}

void	free_data(t_data *data)
{
	ft_lstclear(&data->stack_a, &free);
	ft_lstclear(&data->stack_b, &free);
}
