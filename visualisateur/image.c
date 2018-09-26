/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:54:15 by vduong            #+#    #+#             */
/*   Updated: 2018/09/26 12:54:17 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler_viz.h"

void		init_img(t_envars *env)
{
	t_image	*img;

	img = &env->image;
	img->image = mlx_new_image(env->mlx, env->w, env->h);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->line_s,
								&img->endian);
	img->bpp /= 8;
}

void		img_pixel_put(t_envars *env, double x, double y, int color)
{
	t_image *img;

	img = &(env->image);
	if (x >= 0 && x < env->w && y >= 0 && y < env->h)
		*(int *)(img->ptr + (int)(idx(y, x, env->w) * img->bpp)) = color;
}

void		clear_img(t_envars *env)
{
	t_image *img;

	img = &(env->image);
	ft_bzero(img->ptr, env->size * img->bpp);
}
