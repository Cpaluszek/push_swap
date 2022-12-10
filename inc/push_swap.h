/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:20:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/10 11:34:35 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_stack.h"
// Todo: move to specific location
# define ERROR_STR		"Error\n"
# define INT_MIN_STR	"-2147483648"
# define INT_MAX_STR	"2147483647"

typedef struct s_data
{
	int		value_count;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

// TODO: check for static function
/*	Parsing	*/
int		*parse_args(int argc, char **argv, t_data *data);
int		*parse_str(char *str, t_data *data);
int		*get_array(char **nbrs, int count);

/*	Sort	*/
void	begin_sort(t_data *data);

/*	Instructions	*/
void	push_to_stack(t_stack **src, t_stack **dst);
void	swap_stack(t_stack **src);
void	rotate_stack(t_stack **src);
void	rev_rotate_stack(t_stack **src);

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
void	print_stack(t_stack *stack);

#endif