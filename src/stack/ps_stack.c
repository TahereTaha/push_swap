/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 18:41:13 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/06 09:58:21 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next_node;

	node = stack;
	while (node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	return ;
}

t_node	*ps_init_node(int n, t_node *next, t_node *previous)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return (NULL);
	node->n = n;
	node->next = next;
	node->previous = previous;
	return (node);
}

t_stack	*ps_init_stack(size_t size, int *list)
{
	t_node		*node;
	t_stack		*stack;

	if (size == 0)
		return (NULL);
	stack = NULL;
	while (size--)
	{
		node = ps_init_node(list[size], stack, 0);
		if (!node)
			return (free_stack(stack), NULL);
		if (stack)
			stack->previous = node;
		stack = node;
	}
	while (node->next)
		node = node->next;
	node->next = stack;
	stack->previous = node;
	return (stack);
}

t_stack	**ps_init_stack_ab(size_t size, int *list)
{
	t_stack	**stack_ab;

	stack_ab = ft_calloc(sizeof(t_stack *), 2);
	if (!stack_ab)
		return (NULL);
	stack_ab[0] = ps_init_stack(size, list);
	stack_ab[1] = ps_init_stack(0, NULL);
	if (!stack_ab[0])
		return (free(stack_ab), NULL);
	return (stack_ab);
}

/*

void	ps_s(t_stack *stack)
{
	t_stack	*node_1;
	t_stack	*node_2;
	t_stack	*node_3;
	t_stack	*node_last;

	node_1 = satck;
	node_2 = satck->next;
	node_3 = satck->next->next;
	node_last = satck->previous;
	node_1->next = node_3;
	node_1->previous = node_
	node_3->previous = node_1;
	node_last->next = node_2;
}
*/
