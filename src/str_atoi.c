/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlariono <dlariono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:07:23 by dmitrylario       #+#    #+#             */
/*   Updated: 2023/06/26 17:37:20 by dlariono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	l = ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
	{
		return (ft_strlen(src) + dstsize);
	}
	while (src[i] && l < dstsize - 1)
	{
		dst[l] = src[i];
		l++;
		i++;
	}
	dst[l] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	new_size;
	char	*new;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_size = s1_len + s2_len + 1;
	new = (char *)malloc(new_size);
	if (!new)
		return (0);
	ft_strlcpy(new, s1, new_size);
	ft_strlcat(new, s2, new_size);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	new = (char *)malloc(len + 1);
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}

long	ft_atoi(char *a)
{
	long	nb;
	long	is_neg;
	int		found;

	found = 1;
	nb = 0;
	is_neg = 1;
	while (*a == 32 || (*a >= 9 && *a <= 13))
		a++;
	if (*a == 45)
		is_neg = -1;
	if (*a == 43 || *a == 45)
		a++;
	while (*a && found)
	{
		if (*a >= '0' && *a <= '9')
			nb = nb * 10 + *a - '0';
		else
			found = 0;
		a++;
	}
	return (nb * is_neg);
}
