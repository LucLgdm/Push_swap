/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:45:06 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 03:18:11 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_moves(t_stacks *stacks)
{
	int			i;
	int			size;
	t_stack_a	*head_a;

	head_a = stacks->head_a;
	i = 0;
	size = ft_lstsize_a(head_a);
	while (i++ < size)
	{
		get_top_stack_a(stacks, head_a, i - 1);
		if (head_a->content > stacks->values->max_b
			|| head_a->content < stacks->values->min_b)
			new_max_or_min_stack_b(stacks);
		else
			new_content_b(stacks, head_a->content);
		check_doppel_moves(stacks);
		check_cost(stacks, i);
		head_a = head_a->next;
	}
}

void	check_cost(t_stacks *stacks, int i)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra
		+ stacks->moves->rb + stacks->moves->rr + stacks->moves->rra
		+ stacks->moves->rrb + stacks->moves->rrr;
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

void	check_doppel_moves(t_stacks *stacks)
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

// count the cost to get to the stack b : top of stack a and pb
void	get_top_stack_a(t_stacks *stacks, t_stack_a *head_a, int i)
{
	int	size;

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

int	search_num_stack_b(t_stacks *stacks, int nbr)
{
	t_stack_b	*head_b;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_b = stacks->head_b;
	size = ft_lstsize_b(stacks->head_b);
	while (flag == 0)
	{
		i = 0;
		nbr--;
		head_b = stacks->head_b;
		while (i++ < size)
		{
			if (head_b->content == nbr)
				flag = 1;
			head_b = head_b->next;
		}
	}
	return (nbr);
}
