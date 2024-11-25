/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:30:09 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/08 06:47:32 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ps_stack.h"

void	ps_swap(t_stack **stack_ref)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!stack_ref)
		return ;
	if (ps_stack_size(*stack_ref) <= 1)
		return ;
	first_node = ps_stack_pop(stack_ref);
	second_node = ps_stack_pop(stack_ref);
	ps_stack_push(stack_ref, first_node);
	ps_stack_push(stack_ref, second_node);
	return ;
}

void	ps_sa(t_stack **stack_ab)
{
	ps_swap(&stack_ab[0]);
	return ;
}

void	ps_sb(t_stack **stack_ab)
{
	ps_swap(&stack_ab[1]);
	return ;
}

void	ps_ss(t_stack **stack_ab)
{
	ps_sa(stack_ab);
	ps_sb(stack_ab);
	return ;
}
