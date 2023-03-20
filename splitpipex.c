/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitpipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:33:40 by jmerchan          #+#    #+#             */
/*   Updated: 2023/03/09 13:30:23 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_cwords(char const *str, char s)
{
	int	i;
	int	nwords;

	i = 0;
	nwords = 0;
	while (str[i])
	{
		while (str[i] == s && str[i] != 0)
			i++;
		if (str[i] == '\'' || str[i] == 34)
		{
			i++;
			while ((str[i] != '\'' || str[i] != 34) && str[i] != 0)
				i++;
			if (str[i++] == '\'' || str[i] == 34)
				nwords++;
		}
		while (str[i] != s && str[i] != 0)
		{
			if (str[i + 1] == s || str[i + 1] == 0)
				nwords++;
			i++;
		}
	}
	return (nwords);
}

static char	*ft_word(char const *str, char s)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] != s && str[i] != 0)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	word[i] = 0;
	i = 0;
	while (str[i] != s && str[i] != 0)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

static char	*ft_wordcom(char const *str)
{
	int		i;
	char	*word;
	int		com;

	com = str[0];
	i = 1;
	while (str[i] != 0 && str[i] != com)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	word[i] = 0;
	i = 0;
	word[i] = str[i];
	i++;
	while (str[i] != 0 && str[i] != com)
	{
		word[i] = str[i];
		i++;
	}
	if (str[i] == com)
		word[i] = str[i];
	return (word);
}

char	**ft_splitpipex(char const *str, char c)
{
	char	**split;
	int		is;
	int		i;

	is = 0;
	i = 0;
	split = ft_calloc((ft_cwords(str, c) + 1), sizeof(char *));
	if (!split)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i] != 0)
			i++;
		if (str[i] == '\'' || str[i] == 34)
		{
			split[is++] = ft_wordcom(&str[i++]);
			while ((str[i] != '\'' || str[i] != 34) && str[i] != 0)
				i++;
		}
		else if (str[i] != c && str[i] != 0)
			split[is++] = ft_word(&str[i], c);
		while (str[i] != c && str[i] != 0)
			i++;
	}
	return (split);
}
