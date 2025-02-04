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

t_bool	handle_pipes(t_ms *ms)
{
	int		i;
	t_bool	is_pipe;

	i = 0;
	is_pipe = FALSE;
	if (ms->lexer.tokens[i] == PIPE)
		return (ft_error("Can't start with a PIPE"));
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] != END && ms->lexer.tokens[i] == PIPE)
		{
			is_pipe = TRUE;
			i++;
		}
		while (ms->lexer.tokens[i] == WSPACE)
			i++;
		if (ms->lexer.tokens[i] != END && ms->lexer.tokens[i] == WORD)
		{
			is_pipe = FALSE;
			i++;
		}
		if (is_pipe == TRUE)
			return (ft_error("PIPE must be surronded by WORD"));
		i++;
	}
	return (TRUE);
}
