/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:31:39 by thplessi          #+#    #+#             */
/*   Updated: 2019/07/29 02:06:21 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function split the given string on each occurences of the given
** character and return an array of string.
** Return:	An array of string containing the splited string.
** 			NULL if there is an error in memory allocation.
*/

static void		*ft_freeton(char **arr, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static size_t	ft_countwrd(const char *s, char c)
{
	size_t		i;
	size_t		ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			ret++;
		i++;
	}
	return (ret);
}

static size_t	ft_wrdlen(const char *s, size_t *i, char c)
{
	size_t		len;

	while (s[*i] == c)
		(*i)++;
	len = 0;
	while (s[*i + len] != c && s[*i + len] != 0)
		len++;
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		len;
	size_t		wrd;
	char		**ret;

	if (!s)
		return (NULL);
	wrd = ft_countwrd(s, c);
	ret = (char**)malloc(sizeof(char*) * (wrd + 1));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (j < wrd)
	{
		len = ft_wrdlen(s, &i, c);
		ret[j] = ft_strndup(s + i, len);
		if (!ret[j])
			return (ft_freeton(ret, j));
		i += len;
		j++;
	}
	ret[j] = NULL;
	return (ret);
}
