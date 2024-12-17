/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:10:34 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/17 03:18:04 by lde-merc         ###   ########.fr       */
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

void	new_content_b(t_stacks *stacks, int content)
{
	int	i;
	int	size;
	int	nbr;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = search_num_stack_b(stacks, content);
	if (stacks->head_b->content == nbr)
		return ;
	i = find_index_stack_b(stacks, nbr);
	size = ft_lstsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

void	new_num_in_stack_b(t_stacks *stacks, int num)
{
	int	i;
	int	size;
	int	nbr;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = search_num_stack_b(stacks, num);
	if (stacks->head_b->content == nbr)
		return ;
	i = find_index_stack_b(stacks, nbr);
	size = ft_lstsize_b(stacks->head_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rrb = (size - i);
		else
			stacks->moves->rb = i;
	}
}

int	find_index_stack_b(t_stacks *stacks, int nbr)
{
	t_stack_b	*head_b;
	int			size;
	int			i;

	i = 0;
	head_b = stacks->head_b;
	size = ft_lstsize_b(stacks->head_b);
	while (i < size)
	{
		if (head_b->content == nbr)
			break ;
		head_b = head_b->next;
		i++;
	}
	return (i);
}
