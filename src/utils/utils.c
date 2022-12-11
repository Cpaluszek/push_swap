/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:36 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 11:21:26 by cpalusze         ###   ########.fr       */
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

// Todo: check mallocs protection
void	init_stacks(t_data *data, int *values)
{
	int		i;
	int		*content;
	t_list	*new;

	data->stack_a = NULL;
	i = data->value_count - 1;
	while (i >= 0)
	{
		content = malloc(sizeof(int));
		*content = values[i];
		if (new == NULL)
		{
			free_data(data);
			break ;
		}
		new = ft_lstnew(content);
		if (new == NULL)
		{
			free_data(data);
			break ;
		}
		ft_lstadd_front(&data->stack_a, new);
		i--;
	}
	ft_free(values);
}

void	free_data(t_data *data)
{
	ft_lstclear(&data->stack_a, &free);
	ft_lstclear(&data->stack_b, &free);
}
