/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:52:08 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/17 08:59:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"
#include "libft.h"
#include "ps_shorter.h"
#include "ps_parser.h"
#include <stdlib.h>
#include <unistd.h>

/*
// these are temporal functions 
void	ps_print_stack(t_stack *stack)
{
	int	size;
	int	i;
	int	*list;

	list = ps_stack_value(stack);
	if (!list)
		return ;
	size = ps_stack_size(stack);
	i = 0;
	while (i < size)
	{
		printf("%d\n", list[i]);
		i++;
	}
	free(list);
	return ;
}

void	ps_print_stack_ab(t_stack **stack_ab)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_ab[0];
	printf("\n\n---------a---------\n");
	if (stack_a)
		ps_print_stack(stack_a);
	printf("-------------------\n");
	stack_b = stack_ab[1];
	printf("\n\n---------b---------\n");
	if (stack_b)
		ps_print_stack(stack_b);
	printf("-------------------\n");
}
*/
int	ps_print_operation_list(t_operation *list)
{
	int			i;
	static char	*text[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", \
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	char		*operation;
	int			size;

	if (!list)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	size = list[0];
	list = &list[1];
	i = 0;
	while (i < size)
	{
		operation = text[list[i]];
		if (write(1, operation, ft_strlen(operation)) == -1)
			return (free(&list[-1]), -1);
		i++;
	}
	free(&list[-1]);
	return (1);
}

// these are the real thing than will stay 
int	main(int ac, char **av)
{
	int		*list;
	t_stack	**stack_ab;

	if (ac == 1)
		return (0);
	list = ps_parse_input(ac - 1, ++av);
	if (!list)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_ab = ps_init_stack_ab(ac - 1, list);
	free(list);
	list = ps_short(stack_ab);
	ps_print_operation_list(list);
	ps_stack_clear(stack_ab[0]);
	ps_stack_clear(stack_ab[1]);
	free(stack_ab);
	return (42);
}

//	ps_print_stack_ab(stack_ab);
