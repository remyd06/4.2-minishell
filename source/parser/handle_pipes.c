/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:29:55 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/09 14:37:05 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipes(t_ms *ms)
{
	int	i;

	i = 0;
	if (ms->lexer.tokens[i] == PIPE)
	{
		ft_error(ms, "Pipes must be surrond by words");
		return ;
	}
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == PIPE)
			ms->parser.is_pipe = TRUE;
		i++;
		if (ms->lexer.tokens[i] == PIPE)
			ms->parser.is_pipe = FALSE;
	}
	if (ms->parser.is_pipe == FALSE)
		ft_error(ms, "Pipes must be surrond by words");
}
