/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:12:21 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 02:42:35 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_stacks *stacks, char c)
{
	t_stack_b	*head_b;

	head_b = stacks->head_b;
	if (c == 'a')
	{
		if (head_b == NULL)
			return ;
		else if (head_b->next == NULL)
			ft_last_push_a(stacks);
		else
			ft_push_a(stacks);
	}
	else if (c == 'b')
	{
		if (head_b == NULL)
			ft_first_push_b(stacks);
		else
			ft_push_b(stacks);
	}
}

void	ft_last_push_a(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = (t_stack_a *)stacks->head_b;
	tmp->next = stacks->head_a;
	stacks->head_b = NULL;
	stacks->head_a = tmp;
	ft_printf("pa\n");
}

void	ft_push_a(t_stacks *stacks)
{
	t_stack_a	*tmp;

	tmp = (t_stack_a *)stacks->head_b;
	stacks->head_b = stacks->head_b->next;
	tmp->next = stacks->head_a;
	stacks->head_a = tmp;
	ft_printf("pa\n");
}

void	ft_first_push_b(t_stacks *stacks)
{
	t_stack_b	*tmp;

	tmp = (t_stack_b *)stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	stacks->head_b = tmp;
	stacks->head_b->next = NULL;
	ft_printf("pb\n");
}

void	ft_push_b(t_stacks *stacks)
{
	t_stack_b	*tmp;

	tmp = (t_stack_b *)stacks->head_a;
	stacks->head_a = stacks->head_a->next;
	tmp->next = stacks->head_b;
	stacks->head_b = tmp;
	ft_printf("pb\n");
}
