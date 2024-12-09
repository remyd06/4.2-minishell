/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:24:51 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/09 12:16:05 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_quote(t_ms *ms)
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
		ft_error(ms, "Invalid single quote.");
	 else if (doubleq % 2 == 1)
	 	ft_error(ms, "Invalid double quote.");
}
