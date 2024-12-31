/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:56:30 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/31 14:21:05 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	handle_redir(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->lexer.tokens[i] != END)
	{
		if (ms->lexer.tokens[i] == REDIN || ms->lexer.tokens[i] == REDOUT
			|| ms->lexer.tokens[i] == HEREDOC ||
				ms->lexer.tokens[i] == APPEND_REDIR)
		{
			if (ms->lexer.tokens[i + 1] == WSPACE || ms->lexer.tokens[i + 1] == WORD)
			{
				if (ms->lexer.tokens[i + 1] == WSPACE && ms->lexer.tokens[i + 2] == WORD)
					i++;
				else if (ms->lexer.tokens[i + 1] == WORD)
					i++;
				else
					return (ft_error("REDIR must be follow by a WORD."));
			}
			else if (ms->lexer.tokens[i + 1] == END)
				return (ft_error("REDIR must be followed by a WORD."));
		}
		i++;
	}
	return (TRUE);
}
