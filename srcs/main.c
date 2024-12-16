/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:19:07 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/16 17:45:30 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	error_input(argc, argv);
	stacks.head_a = create_stack_a(argc, argv);
	stacks.head_b = NULL;
	// doppel_check(stacks.head_a);
    // sort(&stacks);

	printstacks(&stacks);
	ft_push(&stacks, 'b');
	ft_printf("First push\n");
	printstacks(&stacks);
	ft_push(&stacks, 'b');
	ft_printf("push normal\n");
	printstacks(&stacks);





	
    free_all(&stacks);
}




void	printstacks(t_stacks *stacks)
{
	t_stack_a *head_a;
	t_stack_b *head_b;
	head_a = stacks->head_a;
	head_b = stacks->head_b;
	ft_printf("stack a		stack b\n");
	for(int i = 0; i < ft_lstsize_a(stacks->head_a); i++){
		if ( i < ft_lstsize_b(stacks->head_b)){
			ft_printf("%i		%i\n", head_a->content, head_b->content);
			head_a = head_a->next;
			head_b = head_b->next;
		}else{
			ft_printf("%i\n", head_a->content);
			head_a = head_a->next;
		}
	}
	ft_printf("\n");
}

