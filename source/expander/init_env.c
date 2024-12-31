/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:41:59 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/31 14:21:54 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_buffers(t_ms *ms)
{
	free(ms->expand.buffer_name);
	free(ms->expand.buffer_arg);
	ms->expand.buffer_name = NULL;
	ms->expand.buffer_arg = NULL;
}

void	split_env(t_ms *ms, int i)
{
		ms->expand.buffer_name = ft_strncpy_exp(ENV[i], '=');
		ms->expand.buffer_arg = ft_strlcpy_exp(ENV[i], '=');
		printf("buffer_name = %s\n", ms->expand.buffer_name);
		printf("buffer_arg = %s\n", ms->expand.buffer_arg);
}

// void	init_env(t_ms *ms, t_env **env)
// {
  
// }
