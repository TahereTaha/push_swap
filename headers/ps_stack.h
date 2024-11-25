/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:58:58 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/09 09:43:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H
# include <aio.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*previous;
	int				n;
}				t_node;

typedef t_node		t_stack;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	STOP = -1
}	t_operation;

typedef t_operation	t_op;

//	functions usefull to work with the stack
t_stack	**ps_init_stack_ab(size_t size, int *list);

void	ps_stack_clear(t_stack *stack);
int		ps_stack_size(t_stack *stack);
t_node	*ps_stack_pop(t_stack **stack_p);
void	ps_stack_push(t_stack **stack_p, t_node *new_node);
int		*ps_stack_value(t_stack *stack);
int		*ps_stack_value_r(t_stack *stack);

void	ps_sa(t_stack **stack_ab);
void	ps_sb(t_stack **stack_ab);
void	ps_ss(t_stack **stack_ab);

void	ps_pa(t_stack **stack_ab);
void	ps_pb(t_stack **stack_ab);

void	ps_ra(t_stack **stack_ab);
void	ps_rb(t_stack **stack_ab);
void	ps_rr(t_stack **stack_ab);

void	ps_rra(t_stack **stack_ab);
void	ps_rrb(t_stack **stack_ab);
void	ps_rrr(t_stack **stack_ab);

#endif
