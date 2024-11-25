/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:01:25 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/06 11:08:29 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"

void	ps_rev_rotate(t_stack **stack_ref)
{
	if (!*stack_ref)
		return ;
	*stack_ref = (*stack_ref)->previous;
	return ;
}

void	ps_rra(t_stack	**stack_ab)
{
	ps_rev_rotate(&stack_ab[0]);
	return ;
}

void	ps_rrb(t_stack	**stack_ab)
{
	ps_rev_rotate(&stack_ab[1]);
	return ;
}

void	ps_rrr(t_stack	**stack_ab)
{
	ps_rra(stack_ab);
	ps_rrb(stack_ab);
	return ;
}
