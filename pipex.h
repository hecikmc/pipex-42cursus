/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:26:27 by jmerchan          #+#    #+#             */
/*   Updated: 2023/03/13 16:52:07 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"

# define N_ARGUMENTS "Invalid number of arguments"
# define PATH_ERROR	"PATH acces error"
# define ERROR_IN "Error infile: no such file or directory: "
# define ERROR_OUT "Error outfile: no such file or directory: "
# define ERROR_CMD "Command not found: "
# define ERROR_PIPE "Error creating pipe"

typedef struct s_pipex
{
	int		exit;
	char	**path;
	char	*cmd1;
	char	*cmd2;
	char	**argm1;
	char	**argm2;
	int		tube[2];
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

void	ft_pipex(char **argm, char **env);
void	ft_checkcmd(t_pipex pipex, char **argm);
void	ft_checkfiles(t_pipex pipex, char **argm);
void	ft_msgerror(char *error, t_pipex pipex);
char	**ft_splitpipex(char const *str, char c);
void	ft_child1(t_pipex pipex, char **env);
void	ft_child2(t_pipex pipex, char **env);
void	ft_freepipex(t_pipex pipex, int cmd);

#endif
