/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:54:57 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 16:51:26 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_home(t_ms *ms);

int	builtin_cd(t_cmd *cmd, t_ms *ms)
{
	char	cwd[BUFSIZ];
	char	old[BUFSIZ];
	int		status_code;

	status_code = 0;
	if (ft_lstsize(cmd->arg) > 1)
	{
		ft_perror("minishell", "cd", NULL, "trop d'arguments");
		return (1);
	}
	getcwd(old, BUFSIZ);
	if (ft_lstsize(cmd->arg) == 0)
		status_code = cd_home(ms);
	else if (chdir((char *) cmd->arg->content) != 0)
	{
		ft_perror("minishell", "cd", (char *) cmd->arg->content, "Aucun fichier ou dossier de ce nom");
		return (1);
	}
	if (status_code == 0)
	{
		getcwd(cwd, BUFSIZ);
		modify_var("OLDPWD", old, true, ms->env);
		modify_var("PWD", cwd, true, ms->env);
	}
	return (status_code);
}

static int	cd_home(t_ms *ms)
{
	char	*home;

	home = search_var("HOME", ms->env);
	if (home == NULL)
	{
		ft_perror("minishell", "cd", NULL, "HOME not set");
		return (1);
	}
	if (chdir(home) != 0)
		return (1);
	return (0);
}
