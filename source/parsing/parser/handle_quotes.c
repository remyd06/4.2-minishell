/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:24:51 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/14 19:15:33 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	convert_single_quotes(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == SINGLE_QUOTE)
		{
			i++;
			while (ms->lexer.tokens[i] != SINGLE_QUOTE)
			{
				ms->lexer.tokens[i] = WORD;
				i++;
			}
		}
		i++;
	}
}

void	convert_double_quotes(t_ms *ms, t_env *env)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i++] == DOUBLE_QUOTE)
		{
			while (ms->lexer.tokens[i] != END
				&& ms->lexer.tokens[i] != DOUBLE_QUOTE)
			{
				if (ms->lexer.tokens[i] == DOLLAR
					&& ms->lexer.tokens[i + 1] == WORD)
				{
					expand_var(ms, env, ++i);
					i++;
				}
				else
					ms->lexer.tokens[i++] = WORD;
			}
		}
		i++;
	}
}

t_bool	handle_quote(t_ms *ms, t_env *env)
{
	int	i;
	int	singleq;
	int	doubleq;

	i = 0;
	singleq = 0;
	doubleq = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == SINGLE_QUOTE)
			singleq++;
		else if (ms->lexer.tokens[i] == DOUBLE_QUOTE)
			doubleq++;
		i++;
	}
	if (singleq % 2 == 1)
		return (ft_error("Invalid single quote."));
	else if (doubleq % 2 == 1)
	 	return (ft_error("Invalid double quote."));
	convert_single_quotes(ms);
	convert_double_quotes(ms, env);
	return (TRUE);
}
