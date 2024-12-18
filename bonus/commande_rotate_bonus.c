/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:55:37 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/18 14:25:22 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stacks *stacks, char c)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		rotate_a(stacks, head_a, 0);
	else if (c == 'b')
		rotate_b(stacks, head_b, 0);
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		rotate_a(stacks, head_a, 0);
		rotate_b(stacks, head_b, 0);
	}
}

void	rotate_a(t_stacks *stacks, t_stack_a *head_a, int n)
{
	t_stack_a	*tmp_head_a;

	tmp_head_a = head_a;
	stacks->head_a = head_a->next;
	while (head_a->next)
		head_a = head_a->next;
	head_a->next = tmp_head_a;
	tmp_head_a->next = NULL;
	if (n != 0)
		ft_printf("ra\n");
}

void	rotate_b(t_stacks *stacks, t_stack_b *head_b, int n)
{
	t_stack_b	*tmp_head_b;

	tmp_head_b = head_b;
	stacks->head_b = head_b->next;
	while (head_b->next)
		head_b = head_b->next;
	head_b->next = tmp_head_b;
	tmp_head_b->next = NULL;
	if (n != 0)
		ft_printf("rb\n");
}
