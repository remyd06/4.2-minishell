/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:31 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/15 19:00:42 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_cmd(t_ms *ms, t_cmd *cmd, size_t index)
{
	ft_strcpy(ms->lexer.tokens_array[index], cmd->cmd);
}

bool	rep_is_cmd(t_ms *ms, t_cmd *cmd, size_t index)
{
	(void) ms;
	(void) cmd;
	if (((index == 0 || ms->lexer.tokens[index - 1] == PIPE)
		|| (ms->lexer.tokens[index - 1] != REDIN
		&& ms->lexer.tokens[index - 1] != REDOUT
		&& ms->lexer.tokens[index - 1] != HEREDOC
		&& ms->lexer.tokens[index - 1] != APPEND_REDIR))
		&& (ft_strlen(ms->lexer.tokens_array[index]) > 0 && ms->lexer.tokens_array[index][0] != '-'))
		return (true);
	return (false);
}
