/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:00:44 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/10 15:04:07 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stacks *stacks)
{
	if (is_sorted(stacks))
		return ;
	if (ft_lstsize_a(stacks->head_a) == 2)
		sort_two(stacks);
}
