/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:19:07 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 02:41:21 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	error_input(argc, argv);
	stacks.head_a = create_stack_a(argc, argv);
	stacks.head_b = NULL;
	doppel_check(stacks.head_a);
	sort(&stacks);
	free_all(&stacks);
	return (0);
}
