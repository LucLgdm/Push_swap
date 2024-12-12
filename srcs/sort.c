/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:00:44 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/12 14:41:40 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stacks *stacks)
{
	int	size_a;

	size_a = ft_lstsize_a(stacks->head_a);
	if (is_sorted(stacks))
		return ;
	else if (size_a == 2)
		sort_two(stacks);
	else if (size_a == 3)
		sort_three(stacks, 1);
	else if (size_a == 4)
		sort_four(stacks);
	else
		sort_multi(stacks);
}
