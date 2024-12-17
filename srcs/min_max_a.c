/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:34:06 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 01:57:16 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_min_max_a(t_stacks *stacks)
{
	t_stack_a	*head_a;
	
	head_a = stacks->head_a;
	stacks->values->min_a = stacks->head_a->content;
	stacks->values->max_a = stacks->head_a->content;
	while (head_a)
	{
		if (head_a->content < stacks->values->min_a)
			stacks->values->min_a = head_a->content;
		if (head_a->content > stacks->values->max_a)
			stacks->values->max_a = head_a->content;
		head_a = head_a->next;
	}
}

/*The function put the new minimum element at the right position in stack a*/
void	new_min_a(t_stacks *stacks)
{
	int	size;
	int	index;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->content != stacks->values->min_a)
	{
		size = ft_lstsize_a(stacks->head_a);
		index = ft_find_index(stacks, stacks->values->min_a);
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				stacks->moves->rra = size - index;
			else
				stacks->moves->ra = index;
		}
		else
		{
			if (index > size / 2)
				stacks->moves->rra = size - index;
			else
				stacks->moves->ra = index;
		}
	}
	apply_moves_min_a(stacks);
}
/*The function put the new maximum element at the right position in stack a*/
void	new_max_a(t_stacks *stacks)
{
	int size;
	int index;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->content != stacks->values->max_a)
	{
		size = ft_lstsize_a(stacks->head_a);
		index = ft_find_index(stacks, stacks->values->max_a);
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				stacks->moves->rra = size - index - 1;
			else
				stacks->moves->ra = index - 1;
		}
		else
		{
			if (index > size / 2)
				stacks->moves->rra = size - index - 1;
			else
				stacks->moves->ra = index - 1;
		}
	}
	apply_moves_max_a(stacks);
}

void    apply_moves_min_a(t_stacks *stacks)
{
    while(stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
    while(stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
    ft_push(stacks, 'a');
}

void    apply_moves_max_a(t_stacks *stacks)
{
    while(stacks->moves->ra-- != 0)
        ft_rotate(stacks, 'a');
    while(stacks->moves->rra-- != 0)
        ft_rotate(stacks, 'a');
    ft_push(stacks, 'a');
    ft_rotate(stacks, 'a');
}
