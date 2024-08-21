/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaucarri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:08:38 by jaucarri          #+#    #+#             */
/*   Updated: 2024/08/04 14:08:39 by jaucarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	normalcorrection(t_calcs *values)
{
	if (values->indexes[0] == 0 && values->use_caps == 1)
		values->result.normal = vector_scale(values->normals[0], -1);
	else if (values->indexes[1] == 0 && values->use_caps == 1)
		values->result.normal = vector_scale(values->normals[1], -1);
	else if (values->indexes[2] == 0 && values->use_caps == 1)
		values->result.normal = vector_scale(values->normals[2], -1);
	else if (values->indexes[0] == 1 && values->use_caps == 1)
		values->result.normal = vector_scale(values->normals[0], -1);
	else if (values->indexes[1] == 1 && values->use_caps == 1)
		values->result.normal = vector_scale(values->normals[1], -1);
	else if (values->indexes[2] == 1 && values->use_caps == 1)
		values->result.normal = vector_scale(values->normals[2], -1);
}

void	initvalues(t_vector3 og, t_vector3 dir, t_vector3 *vert,
		t_calcs *values)
{
	values->result.hit = 0;
	values->edge1 = vector_sub(vert[1], vert[0]);
	values->edge2 = vector_sub(vert[2], vert[0]);
	values->h = vector_cross(dir, values->edge2);
	values->a = vector_dot(values->edge1, values->h);
	values->f = 1.0 / values->a;
	values->s = vector_sub(og, vert[0]);
	values->u = values->f * vector_dot(values->s, values->h);
	values->q = vector_cross(values->s, values->edge1);
	values->v = values->f * vector_dot(dir, values->q);
	values->t = values->f * vector_dot(values->edge2, values->q);
	values->result.rawnormal = vector_normalize(vector_cross(values->edge1,
				values->edge2));
	if (vector_dot(values->result.rawnormal, dir) > 0)
		values->result.rawnormal = vector_scale(values->result.rawnormal, -1);
	values->result.normal = vector_normalize(
			vector_add(vector_add(vector_scale(values->normals[0],
						1 - values->u - values->v),
					vector_scale(values->normals[1], values->u)),
				vector_scale(values->normals[2], values->v)));
	normalcorrection(values);
}

t_intersection	rayintersectstriangle(t_vector3 og, t_vector3 dir,
		t_vector3 *vert, int caps[5])
{
	t_calcs		values;
	t_vector3	point;

	initnormals(vert, caps, &values);
	initvalues(og, dir, vert, &values);
	if (values.a > -EPSILON && values.a < EPSILON)
		return (values.result);
	if (values.u < 0.0 || values.u > 1.0)
		return (values.result);
	if (values.v < 0.0 || values.u + values.v > 1.0)
		return (values.result);
	if (values.t > EPSILON)
	{
		point = vector3_scale_add(dir, values.t, og);
		values.result.hit = 1;
		values.result.point = point;
		values.result.distance = values.t;
		return (values.result);
	}
	else
		return (values.result);
}

t_intersection	intersectrayobject(t_ray ray, t_object *object)
{
	t_vector3		vertex[6];
	t_intersection	closestintersection;
	float			closestdistance;
	int				i[5];
	t_intersection	inter;

	i[0] = 0;
	closestdistance = INFINITY;
	closestintersection.hit = 0;
	while (i[0] < object->tri_count / 3)
	{
		initvertexs(vertex, object, i);
		inter = rayintersectstriangle(ray.origin,
				vector_normalize(ray.direction), vertex, i);
		if (inter.hit == 1 && inter.distance < closestdistance)
		{
			closestintersection = inter;
			closestdistance = inter.distance;
		}
		i[0]++;
	}
	return (closestintersection);
}

t_vector3	getvisibleobjectcolor(t_intersection *closest, t_object *objects,
		int objectcount, t_ray ray)
{
	t_intersection	intersection;
	float			closestdistance;
	t_vector3		color;
	int				i;

	closestdistance = INFINITY;
	color = (t_vector3){0, 0, 1};
	i = 0;
	while (i < objectcount)
	{
		intersection = intersectrayobject(ray, &objects[i]);
		if (intersection.hit && intersection.distance < closestdistance)
		{
			closestdistance = intersection.distance;
			*closest = intersection;
			closest->objindex = i;
			color = objects[i].color;
		}
		i++;
	}
	return (color);
}