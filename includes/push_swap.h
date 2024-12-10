/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:12:55 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/10 14:38:08 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648

// Structures
// Linked list
struct						s_stack_a
{
	int						content;
	struct s_stack_a		*next;
};
typedef struct s_stack_a	t_stack_a;

struct						s_stack_b
{
	int						content;
	struct s_stack_b		*next;
};
typedef struct s_stack_b	t_stack_b;

struct						s_stacks
{
	t_stack_a				*head_a;
	t_stack_b				*head_b;
};
typedef struct s_stacks		t_stacks;

// Error handling
void		error_input(int argc, char **argv);
void		check_integer(int argc, char **argv);
void		check_int_size(int argc, char **argv);
void		doppel_check(t_stack_a *head_a);

// Linked list a
t_stack_a	*create_stack_a(int argc, char **argv);
t_stack_a	*ft_newnode_a(int content);
void		ft_clearnode_a(t_stack_a **head_a);
int			ft_lstsize_a(t_stack_a *head_a);

// Linked list b
void		ft_clearnode_b(t_stack_b **head_b);

// Sort
void		sort(t_stacks *stacks);
bool		is_sorted(t_stacks *stacks);
void		sort_two(t_stacks *stacks);

// Commande swap
void	ft_swap(t_stacks *stacks, char c);
void	swap_a(t_stack_a *head_a, int n);
void	swap_b(t_stack_b *head_b, int n);

// Print
void		print_error_and_exit(void);

// Free
void		free_all(t_stacks *stacks);

#endif

/********************************************
 * Authorized function :                    *
 * read                                     *
 * write                                    *
 * malloc                                   *
 * free                                     *
 * exit                                     *
 *********************************************/