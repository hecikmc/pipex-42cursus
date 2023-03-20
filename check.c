/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:56:03 by jmerchan          #+#    #+#             */
/*   Updated: 2023/03/13 16:50:10 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*ft_getcmderror(char *argm)
{
	int		i;
	char	*cmdnotfound;

	i = 0;
	while (argm[i] != ' ' && argm[i] != 0)
		i++;
	cmdnotfound = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (argm[i] != ' ' && argm[i] != 0)
	{
		cmdnotfound[i] = argm[i];
		i++;
	}
	return (cmdnotfound);
}

void	ft_checkcmd(t_pipex pipex, char **argm)
{
	char	*error;

	if (!pipex.cmd1)
	{
		error = ft_strjoin(ERROR_CMD, ft_getcmderror(argm[2]));
		ft_msgerror(error, pipex);
	}
	else if (!pipex.cmd2)
	{
		error = ft_strjoin(ERROR_CMD, ft_getcmderror(argm[3]));
		ft_msgerror(error, pipex);
	}
}

void	ft_checkfiles(t_pipex pipex, char **argm)
{
	char	*error;

	if (pipex.fd_in < 0)
	{
		error = ft_strjoin(ERROR_IN, argm[1]);
		ft_msgerror(error, pipex);
	}
	if (pipex.fd_out < 0)
	{
		error = ft_strjoin(ERROR_OUT, argm[4]);
		ft_msgerror(error, pipex);
		exit(1);
	}
}

void	ft_msgerror(char *error, t_pipex pipex)
{
	ft_printf("%s\n", error);
	pipex.exit = 1;
}
