/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:48:01 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/14 13:52:44 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	countlen(char *src, char *add)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (src[i])
		i++;
	while (add[j])
		j++;
	res = (i + j);
	return (res);
}

char	*ft_strjoin(char *src, char *add)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	i = 0;
	j = 0;
	k = 0;
	res = malloc(sizeof(char) * (countlen(src, add) + 1));
	while (src[i])
		res[j++] = src[i++];
	while (add[k])
		res[j++] = add[k++];
	res[j] = '\0';
	return (res);
}
