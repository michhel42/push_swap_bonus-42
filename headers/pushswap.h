/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-12 04:44:08 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-12 04:44:08 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

/*
|-------------------------STRUCTURES-------------------------|             */
typedef struct s_value
{
	void	*prev;
	int		value;
	int		cpx_index;
	void	*next;
}	t_value;

typedef struct s_bucket
{
	t_value	*min;
	t_value	*max;
	int		size;
	int		nb;
	int		current;
}	t_bucket;

typedef struct s_operation
{
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
	int	all;
}	t_operation;

typedef enum e_strategy
{
	ERROR = -1,
	NONE = 0,
	ADAPTIVE = 1,
	SIMPLE = 2,
	MEDIUM = 3,
	COMPLEX = 4
}	t_strategy;

typedef struct s_stack
{
	t_value			*a;
	t_value			*b;
	t_operation		total_op;
	float			disorder;
	int				bench;
	int				adaptive;
	int				show;
	int				checker;
	t_strategy		strategy;
}	t_stack;

/*
|-------------------------FUNCTIONS-------------------------|

sort algos:
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                */
void	algo_complex(t_stack *stack);
void	algo_medium(t_stack *stack);
void	algo_simple(t_stack *stack);/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|

init stacks & settings:
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                */
void	find_strategy(char **arg, t_stack *stack);
t_stack	*parse(char **arg, int len, int checker);
char	**get_args(char **arg, int len);
float	compute_disorder(t_value *stack);
float	compute_disorder(t_value *stack);
void	start_algo(t_stack *stack);
int		parse_action(char *buffer, t_stack *stack);/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|

stack operations:
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|              	 */
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ss(t_stack *stack);

void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_rr(t_stack *stack);

void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_rr(t_stack *stack);/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|

struct gestion:
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|              	 */
t_value	*new_node(int value);
void	add_node_back(t_value **lst, t_value *new);
void	add_node_front(t_value **node, t_value *front_node);
void	bzero_op(t_operation *total_op);
int		free_struct(t_value **lst);
int		len_struct(t_value *lst);/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|

// free memory :
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                */
void	error_clear(char **arg, t_stack *stack);
void	clean_args(char **arg);
void	free_all(t_stack *stack);
int		print_error(char *buffer, t_stack *stack);/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|

// stacks utils:
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|                */
t_value	*find_min_value(t_value *lst, int *dir);
t_value	*find_max_value(t_value *lst, int *dir);
int		check_nb(char *nbr, t_value *lst);
void	print_bench(t_stack *stack);/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#endif
