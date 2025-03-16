/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:48:25 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/16 20:57:44 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_free(t_ms *ms, t_env *env)
{
	free_tok(ms);
	free_envarray(ms, NULL);
	free_env(env);
}

int	is_numeric(char *str)
{
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_risdigit(str))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_ms *ms, t_env *env, char **args)
{
	int exit_code;

	printf("exit\n");

	if (args[1])
	{
		if (!is_numeric(args[1]))
		{
			printf("Minishell: exit: %s: numeric argument required\n", args[1]);
			exit_free(ms, env);
			exit(2);
		}
		if (args[2])
		{
			printf("Minishell: exit: too many arguments\n");
			g_exit_status = 1;
			return ;
		}
		exit_code = atoi(args[1]) % 256;
	}
	else
		exit_code = g_exit_status;

	exit(exit_code);
}

