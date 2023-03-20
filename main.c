/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmerchan <jmerchan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:14:25 by jmerchan          #+#    #+#             */
/*   Updated: 2023/03/13 12:22:52 by jmerchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int narg, char **argm, char **env)
{
	if (narg == 5)
		ft_pipex(argm, env);
	else
	{
		ft_printf(N_ARGUMENTS);
		exit (1);
	}
	return (0);
}
