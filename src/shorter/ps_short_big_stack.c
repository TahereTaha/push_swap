/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_short_big_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:55:59 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/17 09:08:32 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"
#include "ps_local_shorter.h"
#include "ps_shorter.h"
#include <stdlib.h>

int		ps_get_index_one_over(t_stack *stack, int value);
int		ps_get_index_one_under(t_stack *stack, int value);
t_op	*ps_optimise_list(t_op *list, int index_a, int index_b, int step);

//	remember that you changed this
int	ps_get_index_chepest_b(t_stack *stack_b, t_stack *stack_a)
{
	int		cost;
	int		size;
	int		min;
	int		min_index;

	stack_b = stack_b->previous;
	size = ps_stack_size(stack_b);
	min = size * ps_stack_size(stack_a) + 1;
	while (size--)
	{
		cost = size;
		if ((ps_stack_size(stack_b) / 2) < cost)
			cost = ft_abs(cost - ps_stack_size(stack_b));
		cost = cost + ft_abs(ps_get_index_one_over(stack_a, stack_b->n));
		if (cost < min)
		{
			min = cost;
			min_index = size;
			if ((ps_stack_size(stack_b) / 2) < min_index)
				min_index -= ps_stack_size(stack_b);
		}
		stack_b = stack_b->previous;
	}
	return (min_index);
}

int	ps_get_index_chepest_a(t_stack *stack_a, t_stack *stack_b)
{
	int		cost;
	int		size;
	int		min;
	int		min_index;

	stack_a = stack_a->previous;
	size = ps_stack_size(stack_a);
	min = size * ps_stack_size(stack_b) + 1;
	while (size--)
	{
		cost = size;
		if ((ps_stack_size(stack_a) / 2) < cost)
			cost = ft_abs(cost - ps_stack_size(stack_a));
		cost = cost + ft_abs(ps_get_index_one_under(stack_b, stack_a->n));
		if (cost < min)
		{
			min = cost;
			min_index = size;
			if ((ps_stack_size(stack_a) / 2) < min_index)
				min_index -= ps_stack_size(stack_a);
		}
		stack_a = stack_a->previous;
	}
	return (min_index);
}

t_op	*ps_push_one_to_a(t_stack **stack_ab, t_op *list)
{
	int	index_a;
	int	index_b;

	index_b = ps_get_index_chepest_b(stack_ab[1], stack_ab[0]);
	list = ps_moveto(stack_ab, index_b, list, 1);
	index_a = ps_get_index_one_over(stack_ab[0], stack_ab[1]->n);
	list = ps_moveto(stack_ab, index_a, list, 0);
	list = ps_optimise_list(list, index_b, index_a, 1);
	ps_pa(stack_ab);
	list = ps_add_operation_to_list(list, PA);
	return (list);
}

t_op	*ps_push_one_to_b(t_stack **stack_ab, t_op *list, int mid_point)
{
	ps_pb(stack_ab);
	list = ps_add_operation_to_list(list, PB);
	if (stack_ab[1]->n < mid_point)
	{
		ps_rb(stack_ab);
		list = ps_add_operation_to_list(list, RB);
	}
	return (list);
}
/*
t_op	*ps_push_one_to_b(t_stack **stack_ab, t_op *list)
{
	int index_a;
	int	index_b;

	index_a = ps_get_index_chepest_a(stack_ab[0], stack_ab[1]);
	list = ps_moveto(stack_ab, index_a, list, 0);
	index_b = ps_get_index_one_under(stack_ab[1], stack_ab[0]->n);
	list = ps_moveto(stack_ab, index_b, list, 1);
	list = ps_optimise_list(list, index_a, index_b, 2);
	ps_pb(stack_ab);
	list = ps_add_operation_to_list(list, PB);
	return (list);
}

*/

t_operation	*ps_short_big_stack(t_stack **stack_ab, t_operation *list)
{
	int	mid_point;

	mid_point = ps_stack_size(stack_ab[0]) / 2;
	ps_pb(stack_ab);
	list = ps_add_operation_to_list(list, PB);
	ps_pb(stack_ab);
	list = ps_add_operation_to_list(list, PB);
	while (ps_stack_size(stack_ab[0]) > 3)
		list = ps_push_one_to_b(stack_ab, list, mid_point);
	if (!(ps_is_stack_ordered(stack_ab[0], 0) > 0))
		list = ps_short_small_stack(stack_ab, list);
	while (ps_stack_size(stack_ab[1]))
		list = ps_push_one_to_a(stack_ab, list);
	return (list);
}
