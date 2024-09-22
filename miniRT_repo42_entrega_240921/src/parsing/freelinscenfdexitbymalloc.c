/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelinscenfdexitbymalloc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:31:51 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:28:22 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	freelinscenfdexitbymalloc(char *line, t_sceneinf *scene, int fd)
{
	free(line);
	clearscene(scene);
	close(fd);
	exiterror(MALLOC_ERROR);
}