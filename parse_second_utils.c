/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_second_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:08:02 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/13 08:22:31 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	c_w(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	**ft_free_ft(char **s, int c)
{
	if (!s)
		return (NULL);
	c -= 1;
	while (c >= 0)
	{
		free(s[c]);
		c--;
	}
	free(s);
	return (NULL);
}

static char	*ft_ge_wo(const char *s, char c)
{
	int		i;
	char	*word;
	int		len;

	i = 0;
	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	p = (char **)malloc((c_w(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			p[i] = ft_ge_wo(s, c);
			if (!p[i])
				return (ft_free_ft(p, i));
			i++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	p[i] = 0;
	return (p);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
