/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_linux_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:25:28 by tatahere          #+#    #+#             */
/*   Updated: 2024/08/17 11:47:21 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_stack.h"
#include "libft.h"
#include "ps_shorter.h"
#include "ps_parser.h"
#include <stdlib.h>
#include <unistd.h>

int	is_cmd(t_stack **stack_ab, char *str)
{
	static void	(*cmd[11])(t_stack **) = {&ps_sa, &ps_sb, &ps_ss, &ps_pa, \
		&ps_pb, &ps_ra, &ps_rb, &ps_rr, &ps_rra, &ps_rrb, &ps_rrr};
	static char	*cmd_str[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", \
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(str, cmd_str[i], ft_strlen(cmd_str[i])))
		{
			cmd[i](stack_ab);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_input(t_stack **stack_ab)
{
	char	*cmd_str;

	cmd_str = get_next_line(0);
	while (cmd_str)
	{
		if (!is_cmd(stack_ab, cmd_str))
			return (free(cmd_str), 0);
		free(cmd_str);
		cmd_str = get_next_line(0);
	}
	return (1);
}

void	free_all(t_stack **stack_ab)
{
	ps_stack_clear(stack_ab[0]);
	ps_stack_clear(stack_ab[1]);
	free(stack_ab);
}

int	main(int ac, char **av)
{
	int		*list;
	t_stack	**stack_ab;
	int		cmd_correct;
	int		stack_shorted;

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
	cmd_correct = check_input(stack_ab);
	stack_shorted = ((ps_is_stack_ordered(stack_ab[0], 0) == 1) && \
			(ps_stack_size(stack_ab[1]) == 0));
	if (stack_shorted == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(stack_ab);
	return (1);
}
