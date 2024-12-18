/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:08:25 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/18 14:36:11 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_all(t_stacks *stacks)
{
	ft_clearnode_a(&stacks->head_a);
	ft_clearnode_b(&stacks->head_b);
}

void	free_and_exit(t_stacks *stacks, char *com)
{
	free_all(stacks);
	free(com);
	print_error_and_exit();
}

bool	is_sorted(t_stacks *stacks)
{
	t_stack_a	*head_a;

	head_a = stacks->head_a;
	while (head_a->next)
	{
		if (head_a->content > head_a->next->content)
			return (false);
		head_a = head_a->next;
	}
	return (true);
}
