/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_local_shorter.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:23:16 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/09 09:23:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_LOCAL_SHORTER_H
# define PS_LOCAL_SHORTER_H

# include "ps_stack.h"
# include "ps_shorter.h"

t_operation	*ps_add_operation_to_list(t_operation *list, t_operation element);
t_operation	*ps_short_small_stack(t_stack **stack_ab, t_operation *list);
t_operation	*ps_short_big_stack(t_stack **stack_ab, t_operation *list);
t_operation	*ps_orient_stack(t_stack **stack_ab, int stack, t_operation *list);

int			ps_stack_get_max(t_stack *stack);
int			ps_stack_get_min(t_stack *stack);
int			ps_is_pair_ordered(t_node *node, int reverse_flag);
int			ps_is_pair_ordered_c(t_node *node, int reverse_flag);
int			ps_is_stack_ordered(t_stack *stack, int reverse_flag);

void		ps_exec_operation_on_stack(t_stack **stack_ab, t_op *list);
t_op		*ps_concat_lists(t_op *list1, t_op *list2);
t_op		*ps_moveto(t_stack **stack_ab, int position, t_op *list, int ab);

#endif
