/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:12:01 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/11 11:00:31 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_rotate(t_stacks *stacks, char c)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	if (c == 'a')
		rev_rotate_a(stacks, 1);
	else if (c == 'b')
		rev_rotate_b(stacks, 1);
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		rev_rotate_a(stacks, 0);
		rev_rotate_b(stacks, 0);
		ft_printf("rrr\n");
	}
}

void	rev_rotate_a(t_stacks *stacks, int n)
{
	t_stack_a	*tmp_head_a;
	t_stack_a	*prev;

	tmp_head_a = stacks->head_a;
	prev = NULL;
	while (tmp_head_a->next)
	{
		prev = tmp_head_a;
		tmp_head_a = tmp_head_a->next;
	}
	prev->next = NULL;
	tmp_head_a->next = stacks->head_a;
	stacks->head_a = tmp_head_a;
	tmp_head_a = NULL;
	if (n != 0)
		ft_printf("rra\n");
}
void	rev_rotate_b(t_stacks *stacks, int n)
{
	t_stack_b	*tmp_head_b;
	t_stack_b	*prev;

	tmp_head_b = stacks->head_b;
	prev = NULL;
	while (tmp_head_b->next)
	{
		prev = tmp_head_b;
		tmp_head_b = tmp_head_b->next;
	}
	prev->next = NULL;
	tmp_head_b->next = stacks->head_b;
	stacks->head_b = tmp_head_b;
	tmp_head_b = NULL;
	if (n != 0)
		ft_printf("rrb\n");
}
