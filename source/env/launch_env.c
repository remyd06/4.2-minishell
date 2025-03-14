/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:25 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/14 14:26:53 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setenv_array(t_ms *ms, char **envp)
{
	int	x;

	x = 0;
	ms->env_array = malloc(sizeof(char *) * (ft_lenarray(envp) + 1));
	while (envp[x])
	{
		ms->env_array[x] = ft_strdup(envp[x]);
		x++;
	}
	ms->env_array[x] = NULL;
}

char	**set_default_env(t_ms *ms, char **envp)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ms->is_env = FALSE;
	envp = malloc(sizeof(char *) * 5);
	envp[0] = ft_strdup("SHLVL=1");
	envp[1] = ft_strjoin("PWD=", pwd);
	envp[2] = ft_strdup("TERM=xterm-256color");
	envp[3] = ft_strdup("_=/usr/bin/env");
	envp[4] = NULL;
	free(pwd);
	return (envp);
}
