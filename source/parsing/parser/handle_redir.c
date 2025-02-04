/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:56:30 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 10:32:33 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	handle_redir(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == REDIN
			|| ms->lexer.tokens[i] == REDOUT
			|| ms->lexer.tokens[i] == HEREDOC
			|| ms->lexer.tokens[i] == APPEND_REDIR)
		{
			i++;
			if (ms->lexer.tokens[i] == END)
				return (ft_error("REDIR must be followed by WORD"));
			while (ms->lexer.tokens[i] == WSPACE)
				i++;
			if (ms->lexer.tokens[i] != WORD
				&& ms->lexer.tokens[i] != SINGLE_QUOTE
				&& ms->lexer.tokens[i] != DOUBLE_QUOTE)
				return (ft_error("REDIR must be followed by WORD"));
		}
		i++;
	}
	return (TRUE);
}
