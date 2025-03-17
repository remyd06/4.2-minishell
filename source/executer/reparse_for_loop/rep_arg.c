/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:26 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/15 18:59:38 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_arg(t_ms *ms, t_cmd *cmd, size_t index)
{
	ft_lstadd_back(&cmd->arg, ft_lstnew(ft_strdup(ms->lexer.tokens_array[index])));
}

bool	rep_is_arg(t_ms *ms, t_cmd *cmd, size_t index)
{
	if (index > 0
		&& ms->lexer.tokens[index - 1] == WORD
		&& ft_strlen(cmd->cmd) > 0
		&& ms->lexer.tokens_array[index][0] != '-')
		return (true);
	return (false);
}
