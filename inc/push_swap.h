/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:20:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/11 12:58:29 by cpalusze         ###   ########.fr       */
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
/*	Parsing	*/
int		*parse_args(int argc, char **argv, t_data *data);
int		*parse_str(char *str, t_data *data);
int		*get_array(char **nbrs, int count);

/*	Sort	*/
void	init_sort(t_data *data);
char	*sort_three(t_list **stack, char *operations);
char	*sort_five(t_list **stack_a, t_list **stack_b, char *operations);

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
int		check_sort(int *array, int size);
int		check_duplicates(int *array, int size);
int		*replace_by_index(int *origin, int count);

/*	Debug	*/
void	print_array(int *array, int count);
void	print_stacks(t_data *data);

#endif