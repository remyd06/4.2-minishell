/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:28:04 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/06 10:34:33 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_token(t_ms *ms)
{
	int		i;

	i = 0;
	while (ft_isspace(ms->input[i]))
		i++;
	while (ms->input[i])
	{	
		if ((ms->input[i] ==  '>' || ms->input[i] == '<') && ms->input[i + 1] == ms->input[i])
		{
			ms->lexer.nb_of_tokens++;
			i += 2;
		}
		else if (ft_ismeta(ms->input[i]) && !ft_isspace(ms->input[i++]))
			ms->lexer.nb_of_tokens++;
		if (ft_isspace(ms->input[i]))
		{
			ms->lexer.nb_of_tokens++;
			while (ft_isspace(ms->input[i]))
				i++;
		}
		else if (ft_isprint(ms->input[i]) && !ft_ismeta(ms->input[i]) && !ft_isspace(ms->input[i]))
		{
			ms->lexer.nb_of_tokens++;
			while (ft_isprint(ms->input[i]) && !ft_ismeta(ms->input[i]) && !ft_isspace(ms->input[i]))
				i++;
		}
	}
	return (ms->lexer.nb_of_tokens);
}
