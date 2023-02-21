/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:50:46 by mpalkov           #+#    #+#             */
/*   Updated: 2022/08/08 15:24:00 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_pri_malloc(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**split;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (0);
	return (split);
}

static int	ft_splitfree(int x, char **split)
{
	while (x >= 0)
	{
		free(split[x]);
		x--;
	}
	free(split);
	return (0);
}

static char	*ft_sec_malloc(size_t i, size_t y, char const *s)
{
	char	*xptr;

	xptr = (char *)malloc(sizeof(char) * (y + 1));
	if (!xptr)
		return (0);
	xptr[y] = 0;
	while (y > 0)
	{
		xptr[y - 1] = s[i];
		y--;
		i--;
	}
	return (xptr);
}

static int	ft_fillsplit(char const *s, char c, char **split, size_t x)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] != c && s [i + 1] != 0)
			y++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			y++;
			split[x] = ft_sec_malloc(i, y, s);
			if (split[x] == NULL)
			{
				ft_splitfree((int)x, split);
				return (0);
			}
			x++;
			y = 0;
		}
		i++;
	}
	split[x] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!s)
		return (0);
	split = ft_pri_malloc(s, c);
	if (!split)
		return (0);
	if (!ft_fillsplit(s, c, split, x))
		return (0);
	return (split);
}

// Allocates (with malloc(3)) and returns an array of strings obtained
// by splitting ’s’ using the character ’c’ as a delimiter.
// The array must end with a NULL pointer.
//
// Parameters
// s: The string to be split.
// c: The delimiter character.
//
// Return value: The array of new strings resulting from the split.
// NULL if the allocation fails.

//1 primary malloc - runs over the original string
//searches for how many "words" the original tring  will be split.
//
//2 fillsplit - runs over the original string and where it detects
//final of a word, it creates ->
//3 secondary malloc for the word and fills it
//with corresponding characters from the original string.
//
////4 if some secondary malloc creation fails, everything created
//until that moment is freed.
