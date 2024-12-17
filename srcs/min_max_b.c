/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:42:47 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 02:43:31 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_min_max_b(t_stacks *stacks)
{
	t_stack_b	*head_b;

	head_b = stacks->head_b;
	stacks->values->min_b = stacks->head_b->content;
	stacks->values->max_b = stacks->head_b->content;
	while (head_b)
	{
		if (head_b->content < stacks->values->min_b)
			stacks->values->min_b = head_b->content;
		if (head_b->content > stacks->values->max_b)
			stacks->values->max_b = head_b->content;
		head_b = head_b->next;
	}
}

void	new_max_or_min_stack_b(t_stacks *stacks)
{
	int	i;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (stacks->head_b->content == stacks->values->max_b)
		return ;
	i = find_index_stack_b(stacks, stacks->values->max_b);
	size = ft_lstsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}
