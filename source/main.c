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

int	g_exit_status = 0;

void	init_infos(t_ms *ms)
{
	ms->lexer.nb_of_tokens = 0;
	ms->lexer.tokens_array = NULL;
	ms->lexer.tokens = NULL;
	ms->parser.nb_pipe = 0;
	ms->is_exit = false;
}

void	main_parsing(t_ms *ms, t_env *env, char **envp)
{
	init_infos(ms);
	ms->input = readline(YEL"MINIS"RED"HELL> "ENDCL);
	if (!ms->input)
	{
		free_envarray(ms, envp);
		free_env(env);
		exit(0);
	}
	if (ms->input && ms->input[0] != ' ')
		add_history(ms->input);
	tokenizer(ms, 0, 0);
	if (parser(ms, env))
		print_tester_value(ms);
	else
		ms->is_error = true;
}

int	main(int __attribute__((unused)) argc, char __attribute((unused)) **argv,
	char **envp)
{
	t_ms	ms;

	ms.is_env = TRUE;
	if (!envp[0])
		envp = set_default_env(&ms, envp);
	setenv_array(&ms, envp);
	init_env(&ms, &ms.env);
	signal(SIGINT, handle_macro);
	signal(SIGQUIT, handle_sigquit);
	main_interface_print();
	while (ms.is_exit == false)
	{
		ms.is_error = false;
		main_parsing(&ms, ms.env, envp);
		if (ms.is_error == false)
			execute(&ms);
		free_tok(&ms);
	}
	free_envarray(&ms, envp);
	free_env(ms.env);
	exit (g_exit_status);
}
