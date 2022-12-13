/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:58:14 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/13 14:44:16 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_split_args(t_data *data, char **nbrs);
static int	*get_array(char **nbrs, int count);

int	*parse_args(int argc, char **argv, t_data *data)
{
	int	i;
	int	*values;

	i = 1;
	while (i < argc)
	{
		if (!check_valid_str(argv[i]) || check_int_overflow(argv[i]))
			arg_error();
		i++;
	}
	data->value_count = argc - 1;
	values = get_array(&argv[1], data->value_count);
	if (values == NULL)
		exit(-1);
	if (check_duplicates(values, data->value_count))
	{
		free(values);
		arg_error();
	}
	return (values);
}

int	*parse_str(char *str, t_data *data)
{
	char	**nbrs;
	int		*values;
	int		i;

	i = 0;
	nbrs = ft_split(str, ' ');
	if (nbrs == NULL)
		exit(-1);
	if (nbrs[i] == NULL)
	{
		free(nbrs);
		arg_error();
	}
	check_split_args(data, nbrs);
	values = get_array(nbrs, data->value_count);
	i = 0;
	while (nbrs && nbrs[i])
		ft_free(nbrs[i++]);
	ft_free(nbrs);
	if (check_duplicates(values, data->value_count))
	{
		ft_free(values);
		arg_error();
	}
	return (values);
}

static void	check_split_args(t_data *data, char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		if (!check_valid_str(nbrs[i]) || check_int_overflow(nbrs[i++]))
		{
			i = 0;
			while (nbrs[i])
				free(nbrs[i]);
			free(nbrs);
			arg_error();
		}
		data->value_count++;
	}
}

static int	*get_array(char **nbrs, int count)
{
	int	*values;
	int	i;

	i = 0;
	values = malloc(sizeof(int) * count);
	if (values == NULL)
		return (NULL);
	while (nbrs[i])
	{
		values[i] = ft_atoi(nbrs[i]);
		i++;
	}
	return (values);
}

void	init_stacks(t_data *data, int *values)
{
	int		i;
	int		*content;
	t_list	*new;

	data->stack_a = NULL;
	data->stack_b = NULL;
	i = data->value_count - 1;
	while (i-- >= 0)
	{
		content = malloc(sizeof(int));
		if (content == NULL)
		{
			free_data(data);
			break ;
		}
		*content = values[i + 1];
		new = ft_lstnew(content);
		if (new == NULL)
		{
			free_data(data);
			break ;
		}
		ft_lstadd_front(&data->stack_a, new);
	}
	free(values);
}
