/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_short_small_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:14:46 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/17 07:14:42 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"
#include "ps_local_shorter.h"
#include "ps_shorter.h"
#include <stdlib.h>

//	important
// this function asumes that there is at least one unorderd pair
int	ps_get_index_unordered_pair(t_stack *stack, int rev)
{
	t_node	*node;
	int		i;

	node = stack;
	i = 0;
	while (ps_is_pair_ordered_c(node, rev) != 0)
	{
		node = node->next;
		i++;
	}
	if ((ps_stack_size(stack) / 2) < i)
		i = i - ps_stack_size(stack);
	return (i);
}

void	ps_exec_operation_on_stack(t_stack **stack_ab, t_op *list)
{
	static void	(*stk_op[])(t_stack **) = {&ps_sa, &ps_sb, &ps_ss, &ps_pa, \
		&ps_pb, &ps_ra, &ps_rb, &ps_rr, &ps_rra, &ps_rrb, &ps_rrr};
	int			size;
	int			i;

	size = list[0];
	list = &list[1];
	i = 0;
	while (size--)
		stk_op[list[i++]](stack_ab);
	return ;
}

t_op	*ps_concat_lists(t_op *list1, t_op *list2)
{
	int		size;
	int		i;
	t_op	*list;

	i = 0;
	size = list1[0] + list2[0];
	list = ft_calloc(sizeof(int), size + 1);
	if (!list)
		return (free(list1), free(list2), list);
	ft_memcpy(&list[1], &list1[1], list1[0] * sizeof(int));
	ft_memcpy(&list[1 + list1[0]], &list2[1], list2[0] * sizeof(int));
	list[0] = size;
	free(list1);
	free(list2);
	return (list);
}

//	important
t_op	*ps_moveto(t_stack **stack_ab, int position, t_op *list, int ab)
{
	t_op	*n_list;

	n_list = ft_calloc(sizeof(int), 1);
	if (!n_list)
		return (free(list), n_list);
	while (position)
	{
		if (position > 0)
			n_list = ps_add_operation_to_list(n_list, RA + ab);
		else
			n_list = ps_add_operation_to_list(n_list, RRA + ab);
		position = position - (position / abs(position));
		if (!n_list)
			return (free(list), n_list);
	}
	ps_exec_operation_on_stack(stack_ab, n_list);
	list = ps_concat_lists(list, n_list);
	return (list);
}

t_operation	*ps_short_small_stack(t_stack **stks, t_operation *list)
{
	ps_sa(stks);
	list = ps_add_operation_to_list(list, SA);
	return (list);
}

/*
t_operation	*ps_short_small_stack(t_stack **stack_ab, t_operation *list)
{
	int	index;

	while (!ps_is_stack_ordered(stack_ab[0], 0))
	{
		index = ps_get_index_unordered_pair(stack_ab[0], 0);
		list = ps_moveto(stack_ab, index, list, 0);
		list = ps_add_operation_to_list(list, SA);
		ps_sa(stack_ab);
	}
	return (list);
}
*/
