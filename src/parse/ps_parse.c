/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:32:33 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/09 09:20:33 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_parser.h"
#include "ps_local_parser.h"
#include "libft.h"
#include <stdlib.h>

// make the list simpler
int	*ps_simplify_list(int size, int *list)
{
	int	i;
	int	j;
	int	count;
	int	*new_list;

	i = 0;
	new_list = ft_calloc(sizeof(int), size);
	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
			if (list[i] > list[j++])
				count++;
		new_list[i] = count;
		i++;
	}
	free(list);
	return (new_list);
}

int	*ps_parse_input(int size, char **strv)
{
	int	i;
	int	*list;

	list = ft_calloc(sizeof(int), size);
	if (ps_haserrors(size, strv) || !list)
		return (free(list), NULL);
	i = 0;
	while (i < size)
	{
		list[i] = ft_atoi(strv[i]);
		i++;
	}
	list = ps_simplify_list(size, list);
	return (list);
}
