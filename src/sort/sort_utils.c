/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:21:49 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 10:37:00 by cpalusze         ###   ########.fr       */
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
	*min = *(int *)st->content;
	while (st)
	{
		if (*(int *)st->content < *min)
		{
			*min = *(int *)st->content;
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
	*max = *(int *)st->content;
	while (st)
	{
		if (*(int *)st->content > *max)
		{
			*max = *(int *)st->content;
			*index = i;
		}
		st = st->next;
		i++;
	}
}

int	get_bits_count(int number)
{
	int bits;

	bits = 0;
	while (number > 0)
	{
		number /= 2;
		bits++;
	}
	return (bits);
}
