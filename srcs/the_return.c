/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:13:56 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/19 13:23:33 by lde-merc         ###   ########.fr       */
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
			new_content_a(stacks, stacks->head_b);
	}
	update_min_max_a(stacks);
	put_in_good_way(stacks);
}

void	new_content_a(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->content != search_stack_a(stacks, head_b->content))
	{
		i = ft_find_index(stacks, search_stack_a(stacks, head_b->content));
		size = ft_lstsize_a(stacks->head_a);
		if (size % 2 == 0)
		{
			if (i + 1 > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
		else
		{
			if (i > size / 2)
				stacks->moves->rra = (size - i);
			else
				stacks->moves->ra = i;
		}
	}
	apply_moves_a(stacks);
}

void	apply_moves_a(t_stacks *stacks)
{
	while (stacks->moves->ra-- != 0)
		ft_rotate(stacks, 'a');
	while (stacks->moves->rra-- != 0)
		ft_rev_rotate(stacks, 'a');
	ft_push(stacks, 'a');
}

void	put_in_good_way(t_stacks *stacks)
{
	int	index;
	int	size;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->head_a->content != stacks->values->min_a)
	{
		index = ft_find_index(stacks, stacks->values->min_a);
		size = ft_lstsize_a(stacks->head_a);
		if (size % 2 == 0)
		{
			if (index > size / 2)
				stacks->moves->ra = index;
			else
				stacks->moves->rra = size - index;
		}
		else
		{
			if (index > size / 2)
				stacks->moves->ra = index;
			else
				stacks->moves->rra = size - index;
		}
	}
	apply_moves_a(stacks);
}

int	search_stack_a(t_stacks *stacks, int nbr)
{
	t_stack_a	*head_a;
	int			size;
	int			flag;
	int			i;

	i = 0;
	flag = 0;
	head_a = stacks->head_a;
	size = ft_lstsize_a(stacks->head_a);
	while (flag == 0)
	{
		i = 0;
		nbr++;
		head_a = stacks->head_a;
		while (i++ < size)
		{
			if (head_a->content == nbr)
				flag = 1;
			head_a = head_a->next;
		}
	}
	return (nbr);
}
