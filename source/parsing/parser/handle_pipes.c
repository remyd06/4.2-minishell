/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:29:55 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/31 14:47:31 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop(t_ms *ms, int *i, t_bool *is_pipe)
{
	if (ms->lexer.tokens[*i] != END && ms->lexer.tokens[*i] == PIPE)
	{
		*is_pipe = TRUE;
		(*i)++;
		while (ms->lexer.tokens[*i] == WSPACE)
			(*i)++;
		if (ms->lexer.tokens[*i] != END && (ms->lexer.tokens[*i] == WORD
				|| ms->lexer.tokens[*i] == DOLLAR
				|| ms->lexer.tokens[*i] == REDIN
				|| ms->lexer.tokens[*i] == REDOUT
				|| ms->lexer.tokens[*i] == HEREDOC
				|| ms->lexer.tokens[*i] == APPEND_REDIR
				|| ms->lexer.tokens[*i] == SINGLE_QUOTE
				|| ms->lexer.tokens[*i] == DOUBLE_QUOTE))
		{
			*is_pipe = FALSE;
			(*i)++;
		}
	}
	(*i)++;
}

t_bool	handle_pipes(t_ms *ms)
{
	int		i;
	t_bool	is_pipe;

	i = 0;
	is_pipe = FALSE;
	if (ms->lexer.tokens[i] == PIPE)
		return (ft_error("Can't start with a PIPE"));
	while (i < ms->lexer.nb_of_tokens)
		loop(ms, &i, &is_pipe);
	if (is_pipe == TRUE)
		return (ft_error("PIPE must be surronded by WORD"));
	return (TRUE);
}
