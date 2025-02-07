/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freebox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:30:49 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 15:09:12 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tok(t_ms *ms)
{
	int	i;

	if (ms->buffer)
		free(ms->buffer);
	i = 0;
	while (ms->lexer.tokens_array && ms->lexer.tokens_array[i])
		free(ms->lexer.tokens_array[i++]);
	free(ms->lexer.tokens_array);
	free(ms->lexer.tokens);
	ms->lexer.tokens_array = NULL;
	ms->lexer.tokens = NULL;
}

void	free_envarray(t_ms *ms)
{
	int	x;

	x = 0;
	while (ms->env_array[x])
		free(ms->env_array[x++]);
	free(ms->env_array);
}

void	free_env(t_env *env)
{
	t_env	*temp;

	while (env)
	{
		temp = env->next;
		free(env->name);
		free(env->arg);
		free(env);
		env = temp;
	}
}
