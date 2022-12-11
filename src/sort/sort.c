/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:06 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 09:29:50 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*sort_three(t_stack **stack, char *instructions, char *temp);

void	begin_sort(t_data *data)
{
	char	*instructions;

	instructions = NULL;
	if (data->value_count == 3)
		instructions = sort_three(&data->stack_a, instructions, NULL);
	ft_printf("%s", instructions);
	print_stack(data->stack_a);
}

static char	*sort_three(t_stack **s, char *instructions, char *temp)
{
	int		two;
	int		three;

	two = (*s)->next->value;
	three = (*s)->next->next->value;
	if ((*s)->value > two && (*s)->value < three)
	{
		temp = ft_strjoin(instructions, "sa\n");
		swap_stack(s);
	}
	else if ((*s)->value > two && two > three)
	{
		temp = ft_strjoin(instructions, "sa\nrra\n");
		swap_stack(s);
		rev_rotate_stack(s);
	}
	else if ((*s)->value > two && two < three)
	{
		temp = ft_strjoin(instructions, "ra\n");
		rotate_stack(s);
	}
	else if ((*s)->value < three && two > three)
	{
		temp = ft_strjoin(instructions, "sa\nra\n");
		swap_stack(s);
		rotate_stack(s);
	}
	else if ((*s)->value < two && two > (*s)->value)
	{
		temp = ft_strjoin(instructions, "rra\n");
		rev_rotate_stack(s);
	}
	return (free(instructions), temp);
}
