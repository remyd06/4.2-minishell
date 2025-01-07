/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:44:34 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 13:41:02 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_lenwords(t_ms *ms, int i)
{
	int		res;

	res = 0;
	while (ms->lexer.tokens[i] != SINGLE_QUOTE
		&& ms->lexer.tokens[i] != DOUBLE_QUOTE)
	{
		res += ft_strlen(ms->lexer.tokens_array[i]);
		i++;
	}
	return (res);
}

void	union_quote(t_ms *ms)
{
	int		i;
	int		j;
	int		buffer_char;
	char	*buffer;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == SINGLE_QUOTE || ms->lexer.tokens[i] == DOUBLE_QUOTE)
		{
			buffer_char = 0;
			ms->lexer.tokens[i] = NA;
			i++;
			buffer = malloc(sizeof(char) * count_lenwords(ms, i) + 1);
			while (ms->lexer.tokens[i + 1] != SINGLE_QUOTE && ms->lexer.tokens[i + 1] != DOUBLE_QUOTE)
			{
				j = 0;
				while (ms->lexer.tokens_array[i][j])
				{
					buffer[buffer_char] = ms->lexer.tokens_array[i][j];
					buffer_char++;
					j++;
				}
				ms->lexer.tokens[i] = NA;
				i++;
			}
		}
		i++;
	}
}
