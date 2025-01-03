/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:00:44 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 01:50:32 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stacks *stacks)
{
	int	size_a;

	if (is_sorted(stacks))
		return ;
	size_a = ft_lstsize_a(stacks->head_a);
	if (size_a == 2)
		sort_two(stacks);
	else if (size_a == 3)
		sort_three(stacks, 1);
	else if (size_a == 4)
		sort_four(stacks);
	ft_push(stacks, 'b');
	ft_push(stacks, 'b');
	ft_find_cheapest(stacks);
	sort_three(stacks, 0);
	move_back_to_a(stacks);
}
