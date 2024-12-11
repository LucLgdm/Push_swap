/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:13:56 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/11 16:33:18 by lde-merc         ###   ########.fr       */
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

void		put_in_good_way(t_stacks *stacks)
{
    /* sort stack a after the return of the element
        using only ra and rra                       */
    
}
