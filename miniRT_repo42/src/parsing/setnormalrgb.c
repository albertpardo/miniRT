/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnormalrgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:29:58 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:35:54 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#define MAX_F_RGB 255.0f

void	setnormalrgb(char *str, t_vector3 *rgb)
{
	setvectorinelemtscene(str, rgb);
	rgb->x /= MAX_F_RGB;
	rgb->y /= MAX_F_RGB;
	rgb->z /= MAX_F_RGB;
}
