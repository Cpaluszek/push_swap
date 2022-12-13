/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:39:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 14:40:50 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compare_three(t_list **s, int a, int b, int c);
static void	compare_three_last_case(t_list **s);

void	sort_three(t_list **s)
{
	int		*one;
	int		*two;
	int		*three;

	one = (*s)->content;
	two = (*s)->next->content;
	three = (*s)->next->next->content;
	compare_three(s, *one, *two, *three);
}

static void	compare_three(t_list **s, int a, int b, int c)
{
	if (a > b && b < c && c > a)
	{
		swap_stack(s);
		ft_printf("sa\n");
	}
	else if (a > b && b > c)
	{
		swap_stack(s);
		rev_rotate_stack(s);
		ft_printf("sa\nrra\n");
	}
	else if (a > b && b < c && c < a)
	{
		rotate_stack(s);
		ft_printf("ra\n");
	}
	else if (a < b && b > c && c > a)
	{
		swap_stack(s);
		rotate_stack(s);
		ft_printf("sa\nra\n");
	}
	else
		compare_three_last_case(s);
}

static void	compare_three_last_case(t_list **s)
{
	rev_rotate_stack(s);
	ft_printf("rra\n");
}
