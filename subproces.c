/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subproces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:52:52 by jmerchan          #+#    #+#             */
/*   Updated: 2023/03/13 16:43:18 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1(t_pipex pipex, char **env)
{
	if (pipex.cmd1 && pipex.fd_in >= 0)
	{
		dup2(pipex.tube[1], 1);
		close(pipex.tube[0]);
		dup2(pipex.fd_in, 0);
		if (ft_strnstr(pipex.argm1[0], "awk", 3))
		{
			if (pipex.argm2[1][0] == '\'')
				pipex.argm1[1] = ft_strtrim(pipex.argm1[1], "'");
			else
				pipex.argm1[1] = ft_strtrim(pipex.argm1[1], "\"");
		}
		if (execve(pipex.cmd1, pipex.argm1, env) == -1)
			pipex.exit = 1;
	}
	else
		pipex.exit = 1;
	exit (pipex.exit);
}

void	ft_child2(t_pipex pipex, char **env)
{
	if (pipex.cmd2)
	{
		dup2(pipex.tube[0], 0);
		close(pipex.tube[1]);
		dup2(pipex.fd_out, 1);
		if (ft_strnstr(pipex.argm2[0], "awk", 3))
		{
			if (pipex.argm2[1][0] == '\'')
				pipex.argm2[1] = ft_strtrim(pipex.argm2[1], "'");
			else
				pipex.argm2[1] = ft_strtrim(pipex.argm2[1], "\"");
		}
		if (execve(pipex.cmd2, pipex.argm2, env) == -1)
			pipex.exit = 1;
	}
	else
		pipex.exit = 127;
	exit (pipex.exit);
}
