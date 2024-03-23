/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:54:11 by dmitrylario       #+#    #+#             */
/*   Updated: 2023/06/26 17:45:51 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*free_me(char **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(*arr);
	return (0);
}

int	word_cnt(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	*word_cpy(const char *s, int start, int delim)
{
	char	*str;
	int		index;
	size_t	len;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (k <= start)
	{
		len = 0;
		while (s[j] == delim)
			j++;
		index = j;
		while (s[j] != delim && s[j] != '\0')
		{
			j++;
			len++;
		}
		if (k == start)
			str = ft_substr(s, index, len);
		k++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		j;

	j = 0;
	arr = malloc((word_cnt(s, c) + 1) * sizeof(char *));
	if (!s || !arr)
		return (0);
	arr[word_cnt(s, c)] = 0;
	while (j < (word_cnt(s, c)))
	{
		arr[j] = word_cpy(s, j, c);
		if (arr[j] == 0)
			return (0);
		j++;
	}
	return (arr);
}

int	isnt_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
			i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
