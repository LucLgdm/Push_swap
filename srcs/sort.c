/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:00:44 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/11 14:49:00 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stacks *stacks)
{
	int	size_a;

	size_a = ft_lstsize_a(stacks->head_a);
	if (is_sorted(stacks))
		return ;
	if (size_a == 2)
		sort_two(stacks);
	if (size_a == 3)
		sort_three(stacks, 1);
	if (size_a == 4)
		sort_four(stacks);
}
