/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:41:59 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/16 22:07:27 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_ms *ms, t_env **env)
{
	int		i;
	t_env	*head;
	t_env	*current;
	t_bool	is_egal;

	i = 0;
	is_egal = (ft_rstrchr(ms->env_array[i], '='));
	head = ft_rlstnew(ft_strncpy_exp(ms->env_array[i], '='),
			ft_strlcpy_exp(ms->env_array[i], '='));
	head->is_egal = is_egal;
	current = head;
	i++;
	while (ms->env_array[i])
	{
		is_egal = (ft_rstrchr(ms->env_array[i], '='));
		if (is_egal)
			current->next = ft_rlstnew(ft_strncpy_exp(ms->env_array[i], '='),
					ft_strlcpy_exp(ms->env_array[i], '='));
		else
			current->next = ft_rlstnew(ft_rstrdup(ms->env_array[i]), "");
		current->next->is_egal = is_egal;
		current = current->next;
		i++;
	}
	*env = head;
}
