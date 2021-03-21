/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:35:53 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/24 17:23:55 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
#define OBJECTS_H

#include "minirt.h"

typedef struct s_parametre
{
    double scal1;
    double scal2;
    double scal3;
    double determinant;
    double t1;
    double t2;
    double solution;
    t_vector distance;
    t_vector discrt;
} t_parametre;

typedef struct s_sphere
{
    int         bug;
    double      radius;
    t_color     color;
    t_vector    position;
    t_vector    center;
    t_vector    translation;
} t_sphere;

typedef struct s_plan
{
    t_vector point;
    t_vector norm;
    t_color  color;
    t_vector translation;
    t_vector rotation;

} t_plan;

typedef struct s_tringle
{
    t_vector    point_a;
    t_vector    point_b;
    t_vector    point_c;
    t_color     color;
    t_vector translation;

}t_triangle;

typedef struct s_square
{
    t_vector    center;
    t_vector    normal;
    double      side_size;
    t_color     color;
    t_vector translation;
    t_vector    rotation;



}t_square;

typedef struct s_cylindre
{
    t_vector    center;
    t_vector    cy_normal;
    t_color     color;
    double      diameter;
    double      height;
    t_vector    translation;
    t_vector    rotation;
}t_cylindre;

#endif