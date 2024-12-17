/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:17:40 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 02:42:18 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_index(t_stacks *stacks, int n)
{
	int			index;
	t_stack_a	*head_a;

	index = 0;
	head_a = stacks->head_a;
	while (head_a->content != n)
	{
		index++;
		head_a = head_a->next;
	}
	return (index);
}
