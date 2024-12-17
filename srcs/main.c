/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:19:07 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 01:48:07 by lde-merc         ###   ########.fr       */
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




void	printstacks(t_stacks *stacks)
{
	t_stack_a *head_a;
	t_stack_b *head_b;
	head_a = stacks->head_a;
	head_b = stacks->head_b;
	ft_printf("stack a\n");
	while (head_a){
		ft_printf("%i\n", head_a->content);
		head_a = head_a->next;
	}
	ft_printf("stack b\n");
	while (head_b){
		ft_printf("%i\n", head_b->content);
		head_b = head_b->next;
	}
}

