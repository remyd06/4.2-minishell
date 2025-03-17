/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_rfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:41 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/16 19:44:30 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_rfo(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index)
{
	int flags;

	cmd->has_file_o = true;
	cmd->has_pipe_o = false;
	ft_strcpy(ms->lexer.tokens_array[index], cmd->rfo);
	flags = ms->lexer.tokens[index - 1] == REDOUT ? (O_WRONLY | O_TRUNC) : (O_WRONLY | O_APPEND);
	ft_close(&exe->fd_o);
	exe->fd_o = open(cmd->rfo, flags | O_CREAT, 0644);
}

bool	rep_is_rfo(t_ms *ms, t_cmd *cmd, size_t index)
{
	(void) cmd;
	if (ms->lexer.tokens[index - 1] == REDOUT || ms->lexer.tokens[index - 1] == APPEND_REDIR)
		return (true);
	return (false);
}
