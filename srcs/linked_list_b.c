/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:10:34 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 00:50:44 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_clearnode_b(t_stack_b **head_b)
{
	t_stack_b	*tmp;

	while (*head_b != NULL)
	{
		tmp = *head_b;
		*head_b = tmp->next;
		free(tmp);
	}
}

int	ft_lstsize_b(t_stack_b *head_b)
{
	int	size;

	size = 0;
	while (head_b != NULL)
	{
		size++;
		head_b = head_b->next;
	}
	return (size);
}
