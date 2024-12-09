/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:37:54 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/09 13:03:07 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(t_ms *ms, char *str)
{
	free_all(ms);
	ms->parser.already_free = TRUE;
	printf(RED"ERROR: %s\n"ENDCL, str);
}
