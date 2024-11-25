/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_shorter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:05:31 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/17 10:35:36 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SHORTER_H
# define PS_SHORTER_H

# include "ps_stack.h"
# include "libft.h"

t_operation	*ps_short(t_stack **stack_ab);
int			ps_is_stack_ordered(t_stack *stack, int reverse_flag);

#endif
