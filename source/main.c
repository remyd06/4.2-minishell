/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:32:56 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/06 15:21:28 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setenv_array(t_ms *ms, char **envp)
{
	int	x;

	x = 0;
	ms->env_array = malloc(sizeof(char *) * (ft_lenarray(envp) + 1));
	while (envp[x])
	{
		ms->env_array[x] = ft_strdup(envp[x]);
		x++;
	}
	ms->env_array[x] = NULL;
}

void	init_infos(t_ms *ms)
{
	ms->lexer.nb_of_tokens = 0;
	ms->lexer.tokens_array = NULL;
	ms->lexer.tokens = NULL;
	ms->parser.nb_pipe = 0;
}

int	main(int __attribute__((unused)) argc, char __attribute((unused)) **argv,
	char **envp)
{
	t_ms	ms;
	t_env	*env = NULL;

	setenv_array(&ms, envp);
	if (envp[0])
		init_env(&ms, &env);
	signal(SIGINT, handle_macro);
	signal(SIGQUIT, handle_sigquit);
	main_interface_print();
	while (1)
	{
		init_infos(&ms);
		ms.buffer = readline(YEL"MINISHELL> "ENDCL);
		if (!ms.buffer)
			break;
		ms.input = ms.buffer;
		if (ms.buffer)
			add_history(ms.buffer);
		tokenizer(&ms);
		if (parser(&ms, env))
			print_tester_value(&ms);
		free_tok(&ms);
	}
	free_envarray(&ms);
	free_env(env);
}
