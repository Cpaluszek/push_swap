/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_detection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:13:38 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/14 15:29:25 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MIN_STR	"-2147483648"
#define INT_MAX_STR	"2147483647"

int	check_valid_str(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] && (ft_isdigit(s[i]) || ft_isspace(s[i]) || s[i] == '-'))
	{
		if ((s[i] == '-') && ((i > 0 && !ft_isspace(s[i - 1]))
				|| (!s[i + 1] || !ft_isdigit(s[i + 1]))))
			break ;
		i++;
	}
	if (s[i] != '\0')
		return (0);
	return (1);
}

int	check_int_overflow(char *s)
{
	int	len;

	len = ft_strlen(s);
	ft_printf("s = (%s) - len = %d\n", s, len);
	if (len < 10)
		return (0);
	if (s[0] == '-')
	{
		if (len > 11 || ft_strncmp(INT_MIN_STR, s, len) < 0)
			return (1);
	}
	else
	{
		if (len > 10 || ft_strncmp(INT_MAX_STR, s, len) < 0)
			return (1);
	}
	return (0);
}

int	check_args_sort(int	*array, int size)
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
