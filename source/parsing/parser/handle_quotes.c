/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:24:51 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 13:59:01 by rdedola          ###   ########.fr       */
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

void	convert_double_quotes(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i++] == DOUBLE_QUOTE)
		{
			while (ms->lexer.tokens[i] != DOUBLE_QUOTE)
			{
				if (ms->lexer.tokens[i] == DOLLAR)
					i++;
				else
				{
					ms->lexer.tokens[i] = WORD;
					i++;
				}
			}
		}
		i++;
	}
}

t_bool	handle_quote(t_ms *ms)
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
	convert_double_quotes(ms);
	convert_single_quotes(ms);
	return (TRUE);
}
