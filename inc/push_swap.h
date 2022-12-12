/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:20:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/12 13:21:52 by cpalusze         ###   ########.fr       */
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

// TODO: check for static function
// TODO: define instructions strings
/*	Parsing	*/
int		*parse_args(int argc, char **argv, t_data *data);
int		*parse_str(char *str, t_data *data);
int		*get_array(char **nbrs, int count);

/*	Sort	*/
void	init_sort(t_data *data);
int		is_sorted(t_list *stack);
char	*sort_three(t_list **stack, char *operations);
char	*sort_five(t_list **stack_a, t_list **stack_b, char *operations);
void	get_lowest_index(t_list **stack, int *min, int *index);

/*	Instructions	*/
void	push_to_stack(t_list **src, t_list **dst);
void	swap_stack(t_list **src);
void	rotate_stack(t_list **src);
void	rev_rotate_stack(t_list **src);

/*	Utils	*/
void	arg_error(void);
void	init_stacks(t_data *data, int *values);
void	free_data(t_data *data);

/*	Error Detection	*/
void	check_valid_str(char *str);
void	check_int_overflow(char *s);
int		check_args_sort(int *array, int size);
int		check_duplicates(int *array, int size);
int		*replace_by_index(int *origin, int count);

/*	Debug	*/
void	print_array(int *array, int count);
void	print_stacks(t_data *data);

#endif