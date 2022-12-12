/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:15:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/12 11:03:45 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#define ERROR_STR "Error\n"

// PARSING:
//		Positive or negative numbers
//		No duplicates
// ARGS:
//		1st arg - top of the stack
// 		./push_swap 1 2 3 4 5 6
// 		./push_swap "1 2 3 4 5 6"
//
// ERRORS:
//		No args return and print nothing
//		Already sort -> print nothing
//		Wrong parameters print `Error\n`
//
// SORT:
// 		smallest on top
// PRINT:
// instruction\n
// Todo: if already sort return 0 and not -1
int	main(int argc, char **argv)
{
	t_data	data;
	int		*values;

	if (argc < 2)
		return (-1);
	if (argc == 2)
		values = parse_str(argv[1], &data);
	else
		values = parse_args(argc, argv, &data);
	if (values == NULL || check_args_sort(values, data.value_count))
	{
		if (values)
			ft_free(values);
		return (-1);
	}
	values = replace_by_index(values, data.value_count);
	init_stacks(&data, values);
	if (data.stack_a == NULL)
		return (0);
	init_sort(&data);
	free_data(&data);
	return (0);
}

void	arg_error(void)
{
	ft_printf_fd(STDOUT_FILENO, ERROR_STR);
	exit(-1);
}
