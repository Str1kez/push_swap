/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:47:38 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:47:39 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handlers.h"

static char	*duplicate(char const *start, char const *end)
{
	size_t	size;
	size_t	i;
	char	*iter;
	char	*res;

	size = 0;
	iter = (char *)start;
	while (iter != end)
	{
		size++;
		iter++;
	}
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = *start;
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

static char	*create_str(char const *s, char c, size_t iter)
{
	char const	*ptr;

	ptr = s;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!iter)
		{
			ptr = s;
			while (*s != c && *s != '\0')
				s++;
			return (duplicate(ptr, s));
		}
		iter--;
		while (*s != c && *s != '\0')
			s++;
	}
	return (duplicate(ptr, s));
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	str_num;
	char	**array;
	size_t	iter;

	if (!s)
	{
		array = (char **)malloc(sizeof(char *));
		array[0] = NULL;
		return (array);
	}
	str_num = word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (str_num + 1));
	if (!array)
		return (NULL);
	iter = 0;
	while (iter < str_num)
	{
		array[iter] = create_str(s, c, iter);
		iter++;
	}
	array[iter] = NULL;
	return (array);
}
