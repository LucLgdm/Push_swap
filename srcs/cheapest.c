/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:57:37 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/12 15:09:20 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_find_cheapest(t_stacks *stacks)
{
    t_moves     *moves;
    t_cheap     *cheap;
    t_values    *values;

    moves = ft_calloc(1, sizeof(t_moves));
    stacks->moves = moves;
    cheap = ft_calloc(1, sizeof(t_cheap));
    stacks->cheap = cheap;
    values = ft_calloc(1, sizeof(t_values));
    stacks->values = values;
    while (ft_lstsize_a(stacks->head_a != 3))
    {
        update_min_max_a(stacks);
        find_moves(stacks);
        apply_cheap_moves(stacks);
    }
}

void    apply_cheap_moves(t_stacks *stacks)
{
    while(stacks->cheap->ra-- != 0)
        ft_rotate(stacks, 'a');
    while(stacks->cheap->rb-- != 0)
        ft_rotate(stacks, 'b');
    while(stacks->cheap->rr-- != 0)
        ft_rotate(stacks, 'r');
    while(stacks->cheap->rra-- != 0)
        ft_rev_rotate(stacks, 'a');
    while(stacks->cheap->rrb-- != 0)
        ft_rev_rotate(stacks, 'b');
    while(stacks->cheap->rrr-- != 0)
        ft_rev_rotate(stacks, 'r');
    while(stacks->cheap->pb-- != 0)
        ft_push(stacks, 'b');
}
