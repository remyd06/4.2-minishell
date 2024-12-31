/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:13:28 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/31 09:43:50 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstnew(char *name, char *arg)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	//new->name = malloc(sizeof(char) * ft_strlen(name));
	new->name = name;
	//new->arg = malloc(sizeof(char) * ft_strlen(arg));
	new->arg = arg;
	new->next = NULL;
	return (new);
}