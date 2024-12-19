/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:48:05 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/19 12:00:53 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			flag;

	if (argc == 1)
		exit(EXIT_FAILURE);
	flag = 0;
	if (ft_strchr(argv[1], ' '))
	{
		argv = ft_split(argv[1], ' ');
		flag = 1;
	}
	error_input(argc, argv, flag);
	stacks.head_a = create_stack_a(argv, flag);
	stacks.head_b = NULL;
	doppel_check(stacks.head_a);
	execute(&stacks);
	free_all(&stacks);
	return (0);
}

void	execute(t_stacks *stacks)
{
	char	*com;

	while (1)
	{
		com = get_next_line(0);
		if (com == NULL)
			break ;
		exec_com(stacks, com);
		free(com);
	}
	if (is_sorted(stacks) && ft_lstsize_b(stacks->head_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	exec_com(t_stacks *stacks, char *com)
{
	if (!ft_strncmp(com, "sa\n", 3))
		ft_swap(stacks, 'a');
	else if (!ft_strncmp(com, "sb\n", 3))
		ft_swap(stacks, 'b');
	else if (!ft_strncmp(com, "pa\n", 3))
		ft_push(stacks, 'a');
	else if (!ft_strncmp(com, "pb\n", 3))
		ft_push(stacks, 'b');
	else if (!ft_strncmp(com, "ra\n", 3))
		ft_rotate(stacks, 'a');
	else if (!ft_strncmp(com, "rb\n", 3))
		ft_rotate(stacks, 'b');
	else if (!ft_strncmp(com, "rr\n", 3))
		ft_rotate(stacks, 'r');
	else if (!ft_strncmp(com, "rra\n", 4))
		ft_rev_rotate(stacks, 'a');
	else if (!ft_strncmp(com, "rrb\n", 4))
		ft_rev_rotate(stacks, 'b');
	else if (!ft_strncmp(com, "rrr\n", 4))
		ft_rev_rotate(stacks, 'r');
	else
		free_and_exit(stacks, com);
}
