/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:36:55 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/09 09:25:10 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ps_stack.h"
#include "ps_shorter.h"

int	ps_stack_get_max(t_stack *stack)
{
	int		midpoint;
	int		max;
	t_node	*node;

	node = stack;
	midpoint = node->n;
	max = midpoint;
	node = node->next;
	while (node->n != midpoint)
	{
		if (node->n > max)
			max = node->n;
		node = node->next;
	}
	return (max);
}

int	ps_stack_get_min(t_stack *stack)
{
	int		midpoint;
	int		min;
	t_node	*node;

	node = stack;
	midpoint = node->n;
	min = midpoint;
	node = node->next;
	while (node->n != midpoint)
	{
		if (node->n < min)
			min = node->n;
		node = node->next;
	}
	return (min);
}

int	ps_is_pair_ordered(t_node *node, int reverse_flag)
{
	int	num_node1;
	int	num_node2;
	int	return_value;

	if (!node || !node->next)
		return (1);
	num_node1 = node->n;
	num_node2 = node->next->n;
	return_value = 0;
	if (num_node1 < num_node2)
		return_value = 1;
	if (reverse_flag)
		return_value = !return_value;
	return (return_value);
}

int	ps_is_pair_ordered_c(t_node *node, int reverse_flag)
{
	if (ps_is_pair_ordered(node, reverse_flag))
		return (1);
	if (!reverse_flag && \
		ps_stack_get_max(node) == node->n && \
		ps_stack_get_min(node) == node->next->n)
		return (1);
	if (reverse_flag && \
		ps_stack_get_min(node) == node->n && \
		ps_stack_get_max(node) == node->next->n)
		return (1);
	return (0);
}

int	ps_is_stack_ordered(t_stack *stack, int reverse_flag)
{
	t_node	*node;

	node = stack;
	if (!ps_is_pair_ordered_c(node, reverse_flag))
		return (0);
	node = node->next;
	while (node != stack)
	{
		if (!ps_is_pair_ordered_c(node, reverse_flag))
			return (0);
		node = node->next;
	}
	if (!reverse_flag && stack->n == ps_stack_get_min(stack))
		return (1);
	if (reverse_flag && stack->n == ps_stack_get_max(stack))
		return (1);
	return (2);
}
