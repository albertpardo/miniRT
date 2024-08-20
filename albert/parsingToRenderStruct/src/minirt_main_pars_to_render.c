/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main_pars_to_render.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:15:00 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/20 10:16:20 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "parsing.h"
#include "testaux.h"

//M_PI definida en math.h

int	main(int argc, char *argv[])
{
	t_sceneinf	scene;

	setsceneorexit(argc, argv[1], &scene);
	printf("\n ==== Scene Width valid Values ====");
	putsceneinfoinline(&scene);
	rendering(&scene);
	clearscene(&scene);
	printf("\n\nPi = %f\n", M_PI);
	return (0);
}
