/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:56 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/27 16:03:25 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define BAD_ARGUMENTS "BAD ARGUMETS. Use : ./minirt NAME.rt"
# define NO_OPEN "open() failed"
# define NO_CLOSE "\nclose() failed" 
# define MALLOC_ERROR "Memory assignament ERROR"
# define BAD_FILETYPE "Filetype is not .rt"
# define EXT ".rt"

// --- Defines for integers checks ----- //

# define CHAR_MAX_RGB "255"
# define CHAR_MAX_FOV "180"
# define INT_NUMDIGITS 3

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

// ---- Diferent elements structs ---- //

typedef struct s_ambientlight
{
	float		lightradio;
	t_vector3	f_rgb;
}	t_ambientlight;

typedef struct s_camera
{
	t_vector3	viewpoint;
	t_vector3	orient;
	float		fov;
}	t_camera;

typedef struct s_light
{
	t_vector3	lightpoint;
	float		brightratio;
	t_vector3	f_rgb;
}	t_light;

typedef struct s_sphere
{
	t_vector3	center;
	float		diameter;
	t_vector3	f_rgb;
}	t_sphere;

typedef struct s_plane
{
	t_vector3	point;
	t_vector3	normal;
	t_vector3	f_rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_vector3	center;
	float		diameter;
	float		height;
	t_vector3	normvector;
	t_vector3	f_rgb;
}	t_cylinder;

// ---- Generic element struct ---- //

typedef struct s_element
{
	int		numline;
	char	*idelement;
	void	*infoelement;
}	t_element;

// ------  parsing -------- //

char	*cleanstringspaces(char *str);
void	exiterror(char *msg);
void	exitifcheckfails(int val, char *msg);
void	exitifnotvalidfiletype(char *fname, char *ext, char *msg);
void	exitifnortfile(char *filename);
void	freearrstr(char **arr);
int		ft_isspace(const char c);
int		isstringvalueinpositiverange(char *str, char *maxintval);
int		isstrfloatcerone(char *str);
void	putarraystr(char **arrstr);

#endif
