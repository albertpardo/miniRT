/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearscene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:43:10 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:26:11 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	delelemlst(void *content)
{
	t_element	*elem;

	elem = content;
	free(elem->idelement);
	free(elem->infoelement);
	free(elem);
}

void	clearscene(t_sceneinf *scene)
{
	free(scene->amb.id);
	free(scene->cam.id);
	free(scene->light.id);
	if (scene->elemlst)
		ft_lstclear(&(scene->elemlst), delelemlst);
}