/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:36 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/16 16:54:22 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_opt(t_ms *ms, t_cmd *cmd, size_t index)
{
	cmd->has_option = true;
	ft_strlcat(cmd->opt, &ms->lexer.tokens_array[index][1], BUFSIZ);
}

bool	rep_is_opt(t_ms *ms, t_cmd *cmd, size_t index)
{
	(void) cmd;
	if (ft_strlen(ms->lexer.tokens_array[index]) > 0 && ms->lexer.tokens_array[index][0] == '-')
		return (true);
	return (false);
}
