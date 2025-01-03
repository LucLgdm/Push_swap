/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:08:25 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/18 11:05:00 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_stacks *stacks)
{
	ft_clearnode_a(&stacks->head_a);
	ft_clearnode_b(&stacks->head_b);
	free(stacks->cheap);
	free(stacks->moves);
	free(stacks->values);
}
