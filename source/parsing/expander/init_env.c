/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:41:59 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 10:17:13 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_ms *ms, t_env **env)
{
	int		i;
	t_env	*head;
	t_env	*current;

	i = 0;
	head = ft_lstnew(ft_strncpy_exp(ms->env_array[i], '='), ft_strlcpy_exp(ms->env_array[i], '='));
	current = head;
	i++;
	while (ms->env_array[i])
	{
		current->next = ft_lstnew(ft_strncpy_exp(ms->env_array[i], '='),
			ft_strlcpy_exp(ms->env_array[i], '='));
		current = current->next;
		i++;
	}
	*env = head;
}
