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

void	init_env(t_env **env)
{
	int		i;
	t_env	*head;
	t_env	*current;

	i = 0;
	head = ft_lstnew(ft_strncpy_exp(ENV[i], '='), ft_strlcpy_exp(ENV[i], '='));
	current = head;
	i++;
	while (ENV[i])
	{
		current->next = ft_lstnew(ft_strncpy_exp(ENV[i], '='),
			ft_strlcpy_exp(ENV[i], '='));
		current = current->next;
		i++;
	}
	*env = head;
}
