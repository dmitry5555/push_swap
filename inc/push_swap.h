/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:25:37 by dlariono          #+#    #+#             */
/*   Updated: 2023/06/28 17:41:47 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	int				val;
	int				i_bs;
}	t_list;

void	free_arr(char **arr);
int		free_list(t_list *head, char **arr, char *str, int err);
int		dup_check(t_list **stack, int num);
void	r_rot(t_list **stack);
void	rot(t_list **stack);
void	push(t_list **stack, int val, int dir);
int		pop(t_list **stack);
int		binary_check(int num, int pos);
int		max_node(t_list **stack);
int		is_sorted(t_list **stack);
int		st_size(t_list **stack);
void	sort_mode(int argc, t_list **stack_a, t_list **stack_b);
void	five_sort(t_list **stack_a, t_list **stack_b);
void	four_sort(t_list **stack_a, t_list **stack_b);
void	three_sort(t_list **stack);
void	index_sort(t_list **stack);
void	any_sort(t_list **stack, int type);
void	radix(t_list **stack_a, t_list **stack_b, int b_dig);
void	swap_help(t_list **head, t_list *node, t_list **prev, t_list **curr);
void	swap(t_list **head, t_list *node1, t_list *node2);
void	sort_b(t_list **stack);
char	**ft_split(char const *s, char c);
void	*free_me(char **arr, int j);
int		word_cnt(const char *str, char c);
char	*word_cpy(const char *s, int start, int delim);
size_t	ft_strlen(const char *a);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(char *a);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
int		input_checker(int argc, char **argv);
int		isnt_digit(char *str);
int		count_arr(char **arr);

#endif