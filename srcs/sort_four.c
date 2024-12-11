/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:08:23 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/11 15:01:42 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_four(t_stacks *stacks)
{
	t_moves		*moves;
	t_cheap		*cheap;
	t_values	*values;

	moves = calloc(1, sizeof(t_moves));
	stacks->moves = moves;
	cheap = ft_calloc(1, sizeof(t_cheap));
	stacks->cheap = cheap;
	values = calloc(1, sizeof(values));
	stacks->values = values;
	ft_push(stacks, 'b');
	sort_three(stacks, 0);
    
	free_all(stacks);
	exit(EXIT_FAILURE);
}
