/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:42:47 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/16 14:43:58 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		update_min_max_b(t_stacks *stacks)
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
