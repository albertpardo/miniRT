/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkisambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:00:25 by apardo-m          #+#    #+#             */
/*   Updated: 2024/09/01 09:35:01 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	checkisambient(char **aelement)
{
	if (ft_astrlen(aelement) == 3)
		if (isstrfloatcerone(aelement[1]) && isrgbstr(aelement[2]))
			return (VALID_ELEMENT);
	return (ERR_IN_FORMAT);
}