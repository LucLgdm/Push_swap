/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:03:24 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/10 15:04:59 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_stacks *stacks)
{
	t_stack_a	*cur;

	if (!stacks || !stacks->head_a)
		return (true);

	cur = stacks->head_a;
	while (cur->next)
	{
		if (cur->content > cur->next->content)
			return (false);
		cur = cur->next;
	}
	ft_clearnode_a(&stacks->head_a);
	exit(EXIT_SUCCESS);
}
