/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhirond <elhirond@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 21:33:45 by elhirond          #+#    #+#             */
/*   Updated: 2025/10/01 13:38:42 by elhirond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Counts the number of words in 's' separated by delimiter 'c'.
 * Param. #1 The input string to scan.
 * Param. #2 The delimiter character.
 * Return value The number of words found.
 */

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

/**
 * Allocates a new string for a word starting at 'start' of length 'len'.
 * Param. #1 Pointer to the start of the word in the source string.
 * Param. #2 The length of the word.
 * Return value Newly allocated null-terminated word, or NULL on failure.
 */

static char	*allocate_word(const char *start, size_t len)
{
	char	*word;

	word = (char *) malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

/**
 * Fills 'result' with split words from 's' using delimiter 'c'.
 * Param. #1 Source string to split.
 * Param. #2 Delimiter character.
 * Param. #3 Output array of strings; must have enough space.
 * Return value 0 on success; index of the failed allocation (to clean) on error.
 */

static int	fill_split(const char *s, char c, char **result)
{
	size_t		i;
	const char	*word_start;
	size_t		word_len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_start = s;
			word_len = 0;
			while (*s && *s != c)
			{
				word_len++;
				s++;
			}
			result[i] = allocate_word(word_start, word_len);
			if (!result[i++])
				return (i);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (0);
}

/**
 * Splits the string 's' into an array of strings using the delimiter 'c'.
 * Allocates memory for the array and each substring. The array is terminated
 * by a NULL pointer.
 * Param. #1 The input string to split.
 * Param. #2 The delimiter character.
 * Return value A newly allocated NULL-terminated array of strings, or NULL on
 * allocation failure or if 's' is NULL.
 */

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**result;
	size_t	fail;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	fail = fill_split(s, c, result);
	if (fail)
	{
		while (fail > 0)
			free(result[--fail]);
		free(result);
		return (NULL);
	}
	return (result);
}
