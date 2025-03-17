/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:19:25 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/17 15:25:11 by rdedola          ###   ########.fr       */
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
		ms->env_array[x] = ft_rstrdup(envp[x]);
		x++;
	}
	ms->env_array[x] = NULL;
}

char	**set_default_env(t_ms *ms, char **envp)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ms->is_env = FALSE;
	envp = malloc(sizeof(char *) * 4);
	envp[0] = ft_rstrdup("SHLVL=1");
	envp[1] = ft_rstrjoin("PWD=", pwd);
	envp[2] = NULL;
	free(pwd);
	return (envp);
}
