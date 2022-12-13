/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:20:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 15:45:46 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_data
{
	int		value_count;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_data;

/*	Parsing	*/
int		*parse_args(int argc, char **argv, t_data *data);
int		*parse_str(char *str, t_data *data);

/*	Sort	*/
void	init_sort(t_data *data);
int		is_sorted(t_list *stack);
void	sort_three(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	get_min_index(t_list **stack, int *min, int *index);

/*	Instructions	*/
void	push_to_stack(t_list **src, t_list **dst);
void	swap_stack(t_list **src);
void	rotate_stack(t_list **src);
void	rev_rotate_stack(t_list **src);

/*	Utils	*/
void	arg_error(void);
int		get_lst_int_value(t_list *stack);
void	init_stacks(t_data *data, int *values);
void	free_data(t_data *data);

/*	Error Detection	*/
int		check_valid_str(char *str);
int		check_int_overflow(char *s);
int		check_args_sort(int *array, int size);
int		check_duplicates(int *array, int size);
int		*replace_by_index(int *origin, int count);

#endif