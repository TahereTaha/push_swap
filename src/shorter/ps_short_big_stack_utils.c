/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_short_big_stack_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:03:42 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/17 09:05:23 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"
#include "ps_local_shorter.h"
#include "ps_shorter.h"
#include <stdlib.h>

int	ps_get_index_one_over(t_stack *stack, int value)
{
	int		min_index;
	int		size;
	int		min;
	t_node	*node;

	if (ps_stack_get_max(stack) < value)
		value = -1;
	node = stack->previous;
	min = ps_stack_get_max(stack) + 1;
	size = ps_stack_size(stack);
	min_index = size;
	while (size--)
	{
		if (node->n > value && node->n < min)
		{
			min = node->n;
			min_index = size;
		}
		node = node->previous;
	}
	if ((ps_stack_size(stack) / 2) < min_index)
		min_index -= ps_stack_size(stack);
	return (min_index);
}

int	ps_get_index_one_under(t_stack *stack, int value)
{
	int		min_index;
	int		size;
	int		min;
	t_node	*node;

	if (ps_stack_get_min(stack) > value)
		value = ps_stack_get_max(stack) + 1;
	node = stack->previous;
	min = ps_stack_get_min(stack) - 1;
	size = ps_stack_size(stack);
	min_index = size;
	while (size--)
	{
		if (node->n < value && node->n > min)
		{
			min = node->n;
			min_index = size;
		}
		node = node->previous;
	}
	if ((ps_stack_size(stack) / 2) < min_index)
		min_index -= ps_stack_size(stack);
	return (min_index);
}

t_op	*ps_optimise_list(t_op *list, int index_a, int index_b, int step)
{
	int		size;
	t_op	*sublist;
	int		i;
	int		min;

	min = ft_abs(index_a);
	if (min > ft_abs(index_b))
		min = ft_abs(index_b);
	size = ft_abs(index_a) + ft_abs(index_b);
	if (0 > (index_a * index_b) || !(index_a * index_b))
		return (list);
	sublist = ft_calloc(sizeof(int), size + 1);
	sublist[0] = ft_abs(index_a);
	if (sublist[0] < ft_abs(index_b))
		sublist[0] = ft_abs(index_b);
	ft_memcpy(&sublist[1], &list[list[0] - size + 1], size * sizeof(int));
	i = 0;
	list[0] = list[0] - size;
	while (i < min)
	{
		sublist[i + 1] += step;
		i++;
	}
	list = ps_concat_lists(list, sublist);
	return (list);
}
