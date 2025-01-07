/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:33:12 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 23:32:55 by rdedola          ###   ########.fr       */
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

void	expand_var(t_ms *ms, t_env *env, int i)
{
	char	*str_env;

	str_env = search_var(ms->lexer.tokens_array[i], env);
	ms->lexer.tokens[i - 1] = NA;
	if (str_env != NULL)
	{
		free(ms->lexer.tokens_array[i]);
		ms->lexer.tokens_array[i] = ft_strdup(str_env);
	}
	else if (str_env == NULL)
	{
		ms->lexer.tokens[i] = NA;
		printf("%s", ms->lexer.tokens_array[i]);
		printf("%d", ms->lexer.tokens[i]);
	}
}
