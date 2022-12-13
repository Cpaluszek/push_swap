/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:21:49 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 11:31:07 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_index(t_list **stack, int *min, int *index)
{
	int		i;
	t_list	*st;

	i = 0;
	*index = 0;
	st = *stack;
	*min = get_lst_int_value(st);
	while (st)
	{
		if (get_lst_int_value(st) < *min)
		{
			*min = get_lst_int_value(st);
			*index = i;
		}
		st = st->next;
		i++;
	}
}

void	get_max_index(t_list **stack, int *max, int *index)
{
	int		i;
	t_list	*st;

	i = 0;
	*index = 0;
	st = *stack;
	*max = get_lst_int_value(st);
	while (st)
	{
		if (get_lst_int_value(st) > *max)
		{
			*max = get_lst_int_value(st);
			*index = i;
		}
		st = st->next;
		i++;
	}
}
