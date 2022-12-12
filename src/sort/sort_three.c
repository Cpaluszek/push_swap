/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:39:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/12 13:07:22 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*compare_three(t_list **s, int a, int b, int c);

//NOTE: is temp useful?
char	*sort_three(t_list **s, char *operations)
{
	int		*one;
	int		*two;
	int		*three;
	char	*temp;

	one = (*s)->content;
	two = (*s)->next->content;
	three = (*s)->next->next->content;
	temp = ft_strjoin(operations, compare_three(s, *one, *two, *three));
	free(operations);
	return (temp);
}

static char	*compare_three(t_list **s, int a, int b, int c)
{
	if (a > b && b < c && c > a)
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
	if (a > b && b < c && c < a)
	{
		rotate_stack(s);
		return ("ra\n");
	}
	if (a < b && b > c && c > a)
	{
		swap_stack(s);
		rotate_stack(s);
		return ("sa\nra\n");
	}
	rev_rotate_stack(s);
	return ("rra\n");
}
