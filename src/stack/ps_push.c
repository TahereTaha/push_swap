/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:31:58 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/06 10:44:53 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	ps_push(t_stack **stack1_ref, t_stack **stack2_ref)
{
	t_node	*node;

	if (!*stack1_ref)
		return ;
	node = ps_stack_pop(stack1_ref);
	ps_stack_push(stack2_ref, node);
	return ;
}

void	ps_pb(t_stack **stack_ab)
{
	ps_push(&stack_ab[0], &stack_ab[1]);
	return ;
}

void	ps_pa(t_stack **stack_ab)
{
	ps_push(&stack_ab[1], &stack_ab[0]);
	return ;
}
