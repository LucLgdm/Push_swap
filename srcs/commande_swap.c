/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:28:16 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/10 14:41:07 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stacks *stacks, char c)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;

	head_a = stacks->head_a;
	head_b = stacks->head_b;
	if (c == 'a')
		swap_a(head_a, 1);
	else if (c == 'b')
	{
		if (head_b == NULL || head_b->next == NULL)
			return ;
		swap_b(head_b, 1);
	}
	else
	{
		if (head_a == NULL || head_a->next == NULL || head_b == NULL
			|| head_b->next == NULL)
			return ;
		swap_a(head_a, 0);
		swap_b(head_b, 0);
		ft_printf("ss\n");
	}
}

void	swap_a(t_stack_a *head_a, int n)
{
	int	tmp;

	tmp = head_a->content;
	head_a->content = head_a->next->content;
	head_a->next->content = tmp;
	if (n != 0)
		ft_printf("sa\n");
}

void	swap_b(t_stack_b *head_b, int n)
{
	int	tmp;

	tmp = head_b->content;
	head_b->content = head_b->next->content;
	head_b->next->content = head_b->content;
	if (n != 0)
		ft_printf("sb\n");
}
