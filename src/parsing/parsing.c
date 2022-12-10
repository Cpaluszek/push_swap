/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:58:14 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/10 12:56:29 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_args(int argc, char **argv, t_data *data)
{
	int	i;
	int	*values;

	i = 1;
	while (i < argc)
	{
		check_valid_str(argv[i]);
		check_int_overflow(argv[i]);
		i++;
	}
	data->value_count = argc - 1;
	values = get_array(&argv[1], data->value_count);
	if (check_duplicates(values, data->value_count))
	{
		ft_free(values);
		arg_error();
	}
	return (values);
}

int	*parse_str(char *str, t_data *data)
{
	int		i;
	char	**nbrs;
	int		*values;

	nbrs = ft_split(str, ' ');
	if (nbrs == NULL)
		exit(-1);
	i = 0;
	while (nbrs[i])
	{
		check_valid_str(nbrs[i]);
		check_int_overflow(nbrs[i++]);
		data->value_count++;
	}
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

int	*get_array(char **nbrs, int count)
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
