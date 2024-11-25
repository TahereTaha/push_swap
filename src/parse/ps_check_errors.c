/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:15:46 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/06 10:22:58 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//	returns 1 on overflow of a int
int	ps_intoverflow(char *str, int sign)
{
	long	first;
	long	second;
	int		i;

	i = 0;
	first = 0;
	second = 0;
	while (ft_isdigit(str[i]))
	{
		first = (first * 10) + (str[i] - '0');
		if (first < second)
			return (1);
		if ((sign && first > 2147483648) || (!sign && first > 2147483647))
			return (1);
		second = first;
		i++;
	}
	return (0);
}

//	returns a 1 if there is no overflow and there are only numbers and sign
int	ps_isint(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = 1;
	if (ps_intoverflow(&str[i], sign))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ps_islistofint(int size, char **strv)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ps_isint(strv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ps_hasduplicates(int size, int *list)
{
	int	i;
	int	j;

	i = 0;
	while ((i + 1) < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] == list[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ps_haserrors(int size, char **strv)
{
	int	i;
	int	*list;

	list = ft_calloc(sizeof(int), size);
	if (!ps_islistofint(size, strv) || !list)
		return (free(list), 1);
	i = 0;
	while (i < size)
	{
		list[i] = ft_atoi(strv[i]);
		i++;
	}
	if (ps_hasduplicates(size, list))
		return (free(list), 1);
	free(list);
	return (0);
}
