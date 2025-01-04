/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:41:59 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/04 14:47:58 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_buffers(t_ms *ms)
{
	if (ms->expand.buffer_name)
	{
		free(ms->expand.buffer_name);
		ms->expand.buffer_name = NULL;
	}
	if (ms->expand.buffer_arg)
	{
		free(ms->expand.buffer_arg);
		ms->expand.buffer_arg = NULL;
	}
}

void	split_env(t_ms *ms, int i)
{
		ms->expand.buffer_name = ft_strncpy_exp(ENV[i], '=');
		ms->expand.buffer_arg = ft_strlcpy_exp(ENV[i], '=');
		// printf("buffer_name = %s\n", ms->expand.buffer_name);
		// printf("buffer_arg = %s\n", ms->expand.buffer_arg);
}

void	init_env(t_ms *ms, t_env **env)
{
	int		i;
	t_env	*new_node;
	t_env	*current;

	i = 0;
	while (ENV[i])
	{
		split_env(ms, i);
		new_node = ft_lstnew(ms->expand.buffer_name, ms->expand.buffer_arg);
		if (*env == NULL)
			*env = new_node;
		else
		{
			current = *env;
			while (current->next != NULL)
				current = current->next;
			current->next = new_node;
		}
		reset_buffers(ms);
		i++;
	}
}
