/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-merc <lde-merc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:12:55 by lde-merc          #+#    #+#             */
/*   Updated: 2024/12/18 16:27:36 by lde-merc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648

// Structures
// Linked list
struct	s_stack_a
{
	int					content;
	struct s_stack_a	*next;
};
typedef struct s_stack_a	t_stack_a;

struct	s_stack_b
{
	int					content;
	struct s_stack_b	*next;
};
typedef struct s_stack_b	t_stack_b;

struct s_values
{
	int	min_a;
	int	max_a;
	int	min_b;
	int	max_b;	
};
typedef struct s_values		t_values;

struct s_moves
{
	int	cost;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
};
typedef struct s_moves		t_moves;

struct s_cheap
{
	int	cost;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
};
typedef struct s_cheap		t_cheap;

struct	s_stacks
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;
	t_values	*values;
	t_moves		*moves;
	t_cheap		*cheap;
};
typedef struct s_stacks		t_stacks;

// Error handling
void		error_input(int argc, char **argv, int flag);
void		check_integer(int argc, char **argv, int flag);
void		check_int_size(int argc, char **argv, int flag);
void		doppel_check(t_stack_a *head_a);

// Linked list a
t_stack_a	*create_stack_a(char **argv, int flag);
t_stack_a	*ft_newnode_a(int content);
void		ft_clearnode_a(t_stack_a **head_a);
int			ft_lstsize_a(t_stack_a *head_a);
void		new_content_a(t_stacks *stacks, t_stack_b *head_b);
void		apply_moves_new_a(t_stacks *stacks);

// Linked list b
void		ft_clearnode_b(t_stack_b **head_b);
int			ft_lstsize_b(t_stack_b *head_b);
void		new_content_b(t_stacks *stacks, int content);

// Min and max a
void		update_min_max_a(t_stacks *stacks);
void		update_min_max_b(t_stacks *stacks);
void		new_min_a(t_stacks *stack);
void		apply_moves_min_a(t_stacks *stacks);
void		new_max_a(t_stacks *stack);
void		apply_moves_max_a(t_stacks *stacks);
int			ft_find_index(t_stacks *stacks, int n);

// Sort
void		sort(t_stacks *stacks);
void		move_back_to_a(t_stacks *stacks);
bool		is_sorted(t_stacks *stacks);
void		sort_two(t_stacks *stacks);
void		sort_three(t_stacks *stacks, int flag);
void		work_number_three(t_stacks *stacks, int num1, int num2, int num3);
void		sort_four(t_stacks *stacks);

// Commande swap
void		ft_swap(t_stacks *stacks, char c);
void		swap_a(t_stack_a *head_a, int n);
void		swap_b(t_stack_b *head_b, int n);

// Commande rotate
void		ft_rotate(t_stacks *stacks, char c);
void		rotate_a(t_stacks *stacks, t_stack_a *head_a, int n);
void		rotate_b(t_stacks *stacks, t_stack_b *head_b, int n);

// Commande reverse rotate
void		ft_rev_rotate(t_stacks *stacks, char c);
void		rev_rotate_a(t_stacks *stacks, int n);
void		rev_rotate_b(t_stacks *stacks, int n);

// Commande push
void		ft_push(t_stacks *stacks, char c);
void		ft_last_push_a(t_stacks *stacks);
void		ft_push_a(t_stacks *stacks);
void		ft_first_push_b(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);

// Return of the Jedi
void		put_in_good_way(t_stacks *stacks);
void		apply_moves_a(t_stacks *stacks);

// Cheap part
void		ft_find_cheapest(t_stacks *stacks);
void		find_moves(t_stacks *stacks);
void		apply_cheap_moves(t_stacks *stacks);
void		get_top_stack_a(t_stacks *stacks, t_stack_a *head_a, int i);
void		check_doppel_moves(t_stacks *stacks);
void		check_cost(t_stacks *stacks, int i);
int			find_index_stack_b(t_stacks *stacks, int nbr);
int			search_num_stack_b(t_stacks *stacks, int nbr);
void		new_max_or_min_stack_b(t_stacks *stacks);
int			search_stack_a(t_stacks *stacks, int nbr);

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