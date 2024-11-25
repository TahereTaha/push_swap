/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:45:36 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/06 10:57:21 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	ps_rotate(t_stack **stack_ref)
{
	if (!*stack_ref)
		return ;
	*stack_ref = (*stack_ref)->next;
	return ;
}

void	ps_ra(t_stack **stack_ab)
{
	ps_rotate(&stack_ab[0]);
	return ;
}

void	ps_rb(t_stack **stack_ab)
{
	ps_rotate(&stack_ab[1]);
	return ;
}

void	ps_rr(t_stack **stack_ab)
{
	ps_ra(stack_ab);
	ps_rb(stack_ab);
	return ;
}
