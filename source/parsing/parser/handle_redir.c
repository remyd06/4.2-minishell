/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:56:30 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/04 14:11:51 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	handle_redir(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == REDIN || ms->lexer.tokens[i] == REDOUT
			|| ms->lexer.tokens[i] == HEREDOC ||
				ms->lexer.tokens[i] == APPEND_REDIR)
		{
			if (ms->lexer.tokens[i + 1] == END)
				return (ft_error("REDIR must be followed by a WORD"));
			i++;
			if (ms->lexer.tokens[i] == WSPACE
				&& (ms->lexer.tokens[i + 1] != WORD))
				return (ft_error("REDIR must be followed by a WORD"));
			else if (ms->lexer.tokens[i] == WORD)
				i++;
		}
		i++;
	}
	return (TRUE);
}
