/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:07:05 by jmerchan          #+#    #+#             */
/*   Updated: 2023/03/13 17:08:14 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_freeall(t_pipex pipex)
{
	int	i;

	i = 0;
	while (pipex.path[i])
	{
		free(pipex.path[i]);
		i++;
	}
	free(pipex.path);
	free(pipex.cmd1);
	free(pipex.cmd2);
	i = 0;
	while (pipex.argm1[i])
	{
		free(pipex.argm1[i]);
		i++;
	}
	free(pipex.argm1);
	i = 0;
	while (pipex.argm2[i])
	{
		free(pipex.argm2[i]);
		i++;
	}
	free(pipex.argm2);
}

static void	ft_closefds(t_pipex pipex)
{
	close(pipex.fd_in);
	close(pipex.fd_out);
	close(pipex.tube[0]);
	close(pipex.tube[1]);
}

static char	**ft_getpath(char **env, t_pipex pipex)
{
	char	**path;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	path = ft_calloc(ft_strlen(env[i] + 5), sizeof(char));
	if (!path)
		ft_msgerror(PATH_ERROR, pipex);
	path = ft_split(env[i] + 5, ':');
	return (path);
}

static char	*ft_getcmd(t_pipex pipex, char *cmd)
{
	int		i;
	char	*aux;
	char	*c;
	char	*ex;

	i = 0;
	while (cmd[i] != 0 && cmd[i] != ' ')
		i++;
	ex = ft_substr(cmd, 0, i);
	i = 0;
	if (access(ex, X_OK) == 0)
		return (ex);
	while (pipex.path[i])
	{
		aux = ft_strjoin(pipex.path[i], "/");
		c = ft_strjoin(aux, ex);
		free (aux);
		if (access(c, X_OK) == 0)
			return (c);
		free (c);
		i++;
	}
	return (NULL);
}

void	ft_pipex(char **argm, char **env)
{
	t_pipex		pipex;

	pipex.exit = 0;
	pipex.path = ft_getpath(env, pipex);
	pipex.fd_in = open (argm[1], O_RDONLY);
	pipex.fd_out = open (argm[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	ft_checkfiles(pipex, argm);
	pipex.cmd1 = ft_getcmd(pipex, argm[2]);
	pipex.cmd2 = ft_getcmd(pipex, argm[3]);
	ft_checkcmd(pipex, argm);
	if (pipe(pipex.tube) < 0)
		perror(ERROR_PIPE);
	pipex.argm1 = ft_splitpipex(argm[2], ' ');
	pipex.argm2 = ft_splitpipex(argm[3], ' ');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_child1(pipex, env);
	ft_child2(pipex, env);
	ft_closefds(pipex);
	ft_freeall(pipex);
	exit(pipex.exit);
}
