/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:01:19 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/06 10:24:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"
#include "libft.h"
#include <stdlib.h>

void	ps_stack_clear(t_stack *stack)
{
	if (!stack)
		return ;
	stack->previous->next = NULL;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->previous);
	}
	free(stack);
	return ;
}

int	ps_stack_size(t_stack *stack)
{
	int		size;
	int		mid_point;
	t_node	*node;

	if (!stack)
		return (0);
	size = 1;
	mid_point = stack->n;
	node = stack->next;
	while (node->n != mid_point)
	{
		size++;
		node = node->next;
	}
	return (size);
}

int	*ps_stack_value(t_stack *stack)
{
	t_node	*node;
	int		size;
	int		i;
	int		*list;

	size = ps_stack_size(stack);
	list = ft_calloc(sizeof(int), size);
	if (!list)
		return (NULL);
	node = stack;
	i = 0;
	while (i < size)
	{
		list[i] = node->n;
		node = node->next;
		i++;
	}
	return (list);
}

t_node	*ps_stack_pop(t_stack **stack_p)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	if (!*stack_p)
		return (NULL);
	first_node = *stack_p;
	second_node = (*stack_p)->next;
	last_node = (*stack_p)->previous;
	second_node->previous = last_node;
	last_node->next = second_node;
	if ((*stack_p)->next != *stack_p)
		*stack_p = second_node;
	else
		*stack_p = NULL;
	first_node->next = NULL;
	first_node->previous = NULL;
	return (first_node);
}

// to be done 
void	ps_stack_push(t_stack **stack_p, t_node *new_node)
{
	t_node	*first_node;
	t_node	*last_node;

	if (!*stack_p)
	{
		*stack_p = new_node;
		new_node->next = new_node;
		new_node->previous = new_node;
		return ;
	}
	first_node = *stack_p;
	last_node = (*stack_p)->previous;
	first_node->previous = new_node;
	last_node->next = new_node;
	*stack_p = new_node;
	(*stack_p)->next = first_node;
	(*stack_p)->previous = last_node;
	return ;
}
