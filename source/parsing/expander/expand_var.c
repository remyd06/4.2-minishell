/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:33:12 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 15:28:32 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_var(char *str, t_env *env)
{
	while (env->next != NULL)
	{
		if (ft_strcmp(str, env->name))
			return (env->arg);
		env = env->next;
	}
	return (NULL);
}

void	expand_var(t_ms *ms, t_env *env)
{
	int		i;
	char	*str_env;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == DOLLAR && ms->lexer.tokens[i + 1] == WORD)
		{
			ms->lexer.tokens[i] = NA;
			i++;
			str_env = search_var(ms->lexer.tokens_array[i], env);
			free(ms->lexer.tokens_array[i]);
			ms->lexer.tokens_array[i] = ft_strdup(str_env);
		}
		i++;
	}
}
