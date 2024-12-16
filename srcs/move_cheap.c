/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:45:06 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/16 15:37:44 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_moves(t_stacks *stacks)
{
	int			i;
	int			size;
	t_stack_a	*head_a;

    head_a = stacks->head_a;
    i = -1;
    size = ft_lstsize_a(head_a);
    while(++i < size)
    {
        get_top_stack_a(stacks, head_a, i);
        if (head_a->content > stacks->values->max_b || \
            head_a->content < stacks->values->min_b)
            update_min_max_b(stacks);
        else
            new_content_b(stacks, head_a->content);\
        check_doppel_moves(stacks);
        check_cost(stacks, i);
        head_a = head_a->next;
    }
}
void    check_cost(t_stacks *stacks, int i)
{
    stacks->moves->cost = stacks->moves->pb + \
    stacks->moves->ra + stacks->moves->rb + stacks->moves->rr + \
    stacks->moves->rra + stacks->moves->rrb + stacks->moves->rrr;
    if (i == 1 || stacks->cheap->cost > stacks->moves->cost)
    {
        stacks->cheap->cost = stacks->moves->cost;
        stacks->cheap->pb = stacks->moves->pb;
        stacks->cheap->ra = stacks->moves->ra;
        stacks->cheap->rb = stacks->moves->rb;
        stacks->cheap->rr = stacks->moves->rr;
        stacks->cheap->rra = stacks->moves->rra;
        stacks->cheap->rrb = stacks->moves->rrb;
        stacks->cheap->rrr = stacks->moves->rrr;
    }
}

void    check_doppel_moves(t_stacks *stacks)
{
    stacks->moves->rr = 0;
    stacks->moves->rrr = 0;
    while (stacks->moves->ra != 0 && stacks->moves->rb != 0)
    {
        stacks->moves->rr++;
        stacks->moves->ra--;
        stacks->moves->rb--;
    }
    while (stacks->moves->rra != 0 && stacks->moves->rrb != 0)
    {
        stacks->moves->rrr++;
        stacks->moves->rra--;
        stacks->moves->rrb--;
    }
}


void		new_content_b(t_stacks *stacks, int content)
{
    t_stack_b   *head_b;
    int         index;
    int         size;

    size = ft_lstsize_b(stacks->head_b);
    index = 0;
    head_b = stacks->head_b;
    stacks->moves->rb = 0;
    stacks->moves->rrb = 0;
    while (content > head_b->content)
    {
        index++;
        head_b = head_b->next;
    }
    if (index > size / 2)
        stacks->moves->rb = index;
    else
        stacks->moves->rrb = size - index;
}

void		get_top_stack_a(t_stacks *stacks, t_stack_a *head_a, int i)
{
    int size;

    stacks->moves->pb = 1;
    stacks->moves->ra = 0;
    stacks->moves->rra = 0;
    size = ft_lstsize_a(stacks->head_a);
    if (stacks->head_a->content == head_a->content)
        return ;
    if (size % 2 == 0)
    {
        if (i + 1 > size / 2)
            stacks->moves->rra = size - i;
        else
            stacks->moves->ra = i;
    }
    else
    {
        if (i > size / 2)
            stacks->moves->rra = size - i;
        else
            stacks->moves->ra = i;
    }
}
