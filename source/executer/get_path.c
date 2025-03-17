/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:33:32 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 15:57:22 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_path(t_cmd *cmd, t_ms *ms)
{
	char	**paths;
	char	*path;
	char	*pathenv;
	size_t	j;

	pathenv = search_var("PATH", ms->env);
	if (access(cmd->cmd, F_OK) == 0 || pathenv == NULL)
		return (ft_strcpy(cmd->cmd, cmd->path), (void) NULL);
	paths = ft_split(pathenv, ':');
	j = 0;
	while (paths[j])
	{
		path = ft_strjoin_mod(ft_strjoin(paths[j], "/"), cmd->cmd);
		if (access(path, F_OK) == 0)
		{
			ft_strcpy(path, cmd->path);
			ft_free_deep(paths);
			return ;
		}
		ft_free(path);
		++j;
	}
	ft_strcpy(cmd->cmd, cmd->path);
	ft_free_deep(paths);
	return ;
}
