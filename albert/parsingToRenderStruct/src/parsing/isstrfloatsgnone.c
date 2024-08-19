/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isstrfloatsgnone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:58:07 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/09 09:15:26 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 * int	isstrfloatsgnone(char *str)
 * 
 * checks if str is in range [-1.0,1.0]
 */

int	isstrfloatsgnone(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '+' || *str == '-')
		return (0);
	return (isstrfloatcerone(str));
}