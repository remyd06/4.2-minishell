/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:38:47 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/17 17:38:47 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_fd(void)
{
	if (!isatty(STDIN_FILENO))
	{
		printf("exit");
		exit(1);
	}
	else if (!isatty(STDOUT_FILENO))
	{
		printf("exit");
		exit(1);
	}
	else if (!isatty(STDERR_FILENO))
	{
		printf("exit");
		exit(1);
	}
	return ;
}