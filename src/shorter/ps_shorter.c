/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_shorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:44:52 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/17 08:59:51 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_shorter.h"
#include "libft.h"
#include "ps_local_shorter.h"
#include "ps_stack.h"
#include <stdlib.h>
#include <stdio.h>

t_operation	*ps_add_operation_to_list(t_operation *list, t_operation element)
{
	t_operation	*tmp;
	int			size;

	size = list[0] + 1;
	tmp = ft_calloc(sizeof(int), size + 1);
	if (!tmp)
		return (free(list), NULL);
	ft_memcpy(tmp, list, size * sizeof(int));
	free(list);
	list = tmp;
	list[0] = size;
	list[size] = element;
	return (list);
}

int	ps_get_index_start(t_stack *stack)
{
	t_node	*node;
	int		i;

	node = stack;
	i = 0;
	while (node->n != ps_stack_get_min(stack))
	{
		node = node->next;
		i++;
	}
	if ((ps_stack_size(stack) / 2) < i)
		i = i - ps_stack_size(stack);
	return (i);
}

t_operation	*ps_orient_stack(t_stack **stack_ab, int stack, t_operation *list)
{
	int	index;

	index = ps_get_index_start(stack_ab[stack]);
	list = ps_moveto(stack_ab, index, list, stack);
	return (list);
}

t_operation	*ps_short(t_stack **stack_ab)
{
	t_operation	*list;

	list = 0;
	list = ft_calloc(sizeof(int), 1);
	if (!list)
		return (list);
	if (ps_stack_size(stack_ab[0]) < 2)
		return (list);
	if (ps_is_stack_ordered(stack_ab[0], 0) > 0)
		return (ps_orient_stack(stack_ab, 0, list));
	if (ps_stack_size(stack_ab[0]) < 4)
		list = ps_short_small_stack(stack_ab, list);
	else
		list = ps_short_big_stack(stack_ab, list);
	if (!list)
		return (list);
	list = ps_orient_stack(stack_ab, 0, list);
	return (list);
}
