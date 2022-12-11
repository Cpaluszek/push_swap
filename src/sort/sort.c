/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:06 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 11:37:16 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*sort_three(t_list **stack, char *instructions);
static char	*compare_three(t_list **s, int a, int b, int c);

// Todo: sort 2 ?
void	begin_sort(t_data *data)
{
	char	*instructions;

	instructions = NULL;
	if (data->value_count == 3)
		instructions = sort_three(&data->stack_a, instructions);
	ft_printf("%s", instructions);
	ft_printf("------\n");
	print_stack(data->stack_a);
}

static char	*sort_three(t_list **s, char *instructions)
{
	int		*one;
	int		*two;
	int		*three;
	char	*temp;

	one = (*s)->content;
	two = (*s)->next->content;
	three = (*s)->next->next->content;
	temp = ft_strjoin(instructions, compare_three(s, *one, *two, *three));
	free(instructions);
	return (temp);
}

// Note: expand conditions with all tests ?
// a-b - b-c - c-a
static char	*compare_three(t_list **s, int a, int b, int c)
{
	if (a > b && a < c)
	{
		swap_stack(s);
		return ("sa\n");
	}
	if (a > b && b > c)
	{
		swap_stack(s);
		rev_rotate_stack(s);
		return ("sa\nrra\n");
	}
	if (a > b && b < c)
	{
		rotate_stack(s);
		return ("ra\n");
	}
	if (a < c && b > c)
	{
		swap_stack(s);
		rotate_stack(s);
		return ("sa\nra\n");
	}
	rev_rotate_stack(s);
	return ("rra\n");
}
