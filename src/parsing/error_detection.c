/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_detection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:13:38 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/08 09:26:13 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_valid_str(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || ft_isspace(s[i]) || s[i] == '-'))
		i++;
	if (s[i] != '\0')
		arg_error();
	check_int_overflow(s);
}

void	check_int_overflow(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len < 10)
		return ;
	if (s[0] == '-' && ft_strncmp(INT_MIN_STR, s, len) < 0)
		arg_error();
	else if (ft_strncmp(INT_MAX_STR, s, len) < 0)
		arg_error();
}

int	check_sort(int	*array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
			if (array[i] == array[j++])
				return (1);
		i++;
	}
	return (0);
}
