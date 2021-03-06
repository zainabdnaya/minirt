/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:33:12 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/28 01:59:44 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

int		mlx_close(t_minirt *rt)
{
	(void)rt;
	exit(0);
	return (0);
}

int		key_hook(int key, t_minirt *rt)
{
	(void)rt;
	if (key == 53)
		exit(0);
	return (0);
}

void	key_press1(int keycode, t_minirt *rt)
{
	if (rt->stc.j == 0)
	{
		rt->new_camtmp = rt->list_camera;
		rt->stc.j = 1;
		rt->stc.size = ft_lstsize(rt->new_camtmp);
	}
	if (keycode == 8)
		rt->active = 1;
	if (keycode == 126 && rt->active == 1)
	{
		if (rt->stc.size == rt->stc.i)
		{
			rt->list_camera = rt->new_camtmp;
			rt->stc.i = 0;
		}
		else
			rt->list_camera = rt->list_camera->next;
		build_image(rt, rt->list_camera->look_at);
		mlx_put_image_to_window(rt->mlx.mlx_ptr,\
				rt->mlx.win, rt->mlx.img_ptr, 0, 0);
		rt->stc.i++;
	}
}

void	key_press2(int keycode, t_minirt *rt)
{
	if (keycode == 125 && rt->active == 1 && rt->list_camera->previous != NULL)
	{
		rt->list_camera = rt->list_camera->previous;
		build_image(rt, rt->list_camera->look_at);
		mlx_put_image_to_window(rt->mlx.mlx_ptr, \
				rt->mlx.win, rt->mlx.img_ptr, 0, 0);
	}
}

int		key_press(int keycode, t_minirt *rt)
{
	key_press1(keycode, rt);
	key_press2(keycode, rt);
	return (0);
}
