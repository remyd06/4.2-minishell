/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:40:57 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/17 16:54:08 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(t_cmd *cmd)
{
	bool	nl;
	t_list	*temp;

	temp = cmd->arg;
	nl = true;
	if (ft_strchr(cmd->opt, 'n') != NULL)
		nl = false;
	while (temp)
	{
		ft_write(STDOUT_FILENO, temp->content);
		if (temp->next)
			ft_write(STDOUT_FILENO, " ");
		temp = temp->next;
	}
	if (nl)
		ft_write(STDOUT_FILENO, "\n");
	return (0);
}
