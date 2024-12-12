/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:13:56 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/12 10:53:40 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_back_to_a(t_stacks *stacks)
{
	while (stacks->head_b != NULL)
    {
        update_min_max_a(stacks);
        if (stacks->head_b->content < stacks->values->min_a)
            new_min_a(stacks);
        else if (stacks->head_b->content > stacks->values->max_a)
            new_max_a(stacks);
        else
            new_content_a(stacks);
    }
    update_min_max_a(stacks);
    put_in_good_way(stacks);
}

void	new_content_a(t_stacks *stacks)
{
	int 		size;
	int 		index;
	t_stack_a 	*head_a;

	head_a = stacks->head_a;
	size = ft_lstsize_a(stacks->head_a);
	index = 0;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	while (stacks->head_b->content > head_a->content)
	{
		index++;
		head_a = head_a->next;
	}
	if (index > size / 2)
		stacks->moves->ra = index;
	else
		stacks->moves->rra = size - index;
	apply_moves_a(stacks);
}

void    apply_moves_a(t_stacks *stacks)
{
    while (stacks->moves->ra != 0)
    {
        ft_rotate(stacks, 'a');
        stacks->moves->ra--;
    }
    while (stacks->moves->rra != 0)
    {
        ft_rev_rotate(stacks, 'a');
        stacks->moves->rra--;
    }
    ft_push(stacks, 'a');
}

void	put_in_good_way(t_stacks *stacks)
{
    /* sort stack a after the return of the elements
        using only ra and rra.
        The goal is to put the min at the top
        and the max at the bottom                   */
    int index;
    int size;
    
    index = ft_find_index(stacks, stacks->values->min_a);
    size = ft_lstsize_a(stacks->head_a);
    if (size % 2 == 0)
    {
        if (index - 1 > size / 2)
            stacks->moves->ra = index - 1;
        else
            stacks->moves->rra = size - index - 1;
    }
    else
    {
        if (index > size /2)
            stacks->moves->ra = index;
        else
            stacks->moves->rra = size - index;
    }
    apply_moves_a(stacks);
}
