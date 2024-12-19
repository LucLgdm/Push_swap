/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:19:07 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/19 13:23:54 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	sort(&stacks);
	free_all(&stacks);
	return (0);
}
