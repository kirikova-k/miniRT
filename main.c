/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:10:05 by fbeatris          #+#    #+#             */
/*   Updated: 2022/02/14 15:30:54 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_usage(void)
{
	ft_putstr_fd(GREEN"			~~~~~~~~~~U S A G E~~~~~~~~~~\n\n"DEFAULT, 1);
	ft_putstr_fd(BLUE"[esc]\033[0;37m \033[3;45m/exit/\033[0;37m			\
	\033[3;45m/moove\033[0;37m   \033[3;45m/moove\033[0;37m    \033[3;45m", 1);
	ft_putstr_fd("/tilt obj\033[0;37m  \033[3;45m/size\033[0;37m\n", 1);
	ft_putstr_fd("					\033[3;45mobj(z++)/\033[0;37m ", 1);
	ft_putstr_fd("\033[3;45mobj(x++)/\033[0;37m\033[3;45mright/\033[0;37m", 1);
	ft_putstr_fd("    \033[3;45mobj--/\033[0;37m\n", 1);
	ft_putstr_fd("						 7️⃣	8️⃣	9️⃣	\033[1;47m➖\
	\033[0;37m\n	\033[3;45m/rotate\033[0;37m     \033[1;36m[W]\033[0;37m	\
		\033[3;45m/moove\033[0;37m		  \033[3;45m/moove obj\033[0;37m ", 1);
	ft_putstr_fd(B_PINK"/size++/\033[0;37m\n	\033[3;45mcamera/"DEFAULT, 1);
	ft_putstr_fd(BLUE"	[A] [S] [D]\033[0;37m		\033[3;45mobj(y--)/", 1);
	ft_putstr_fd("\033[0;37m4️⃣	5️⃣ \033[3;45m(y++)/\033[0;37m6️⃣\033[1;47m\
	➕\033[0;37m\n					\n", 1);
	ft_putstr_fd(BLUE"[⬆ shift]\033[0;37m\033[3;45m/zoom++/\033[0;37m", 1);
	ft_putstr_fd("     \033[3;45m/moove\033[0;37m\033[1;36mᐃ\033[0;37m\
		   \033[3;45m/moove\033[0;37m1️⃣ \033[3;45mmoove\033[0;37m2️⃣ ", 1);
	ft_putstr_fd(" \033[3;45m/tilt\033[0;37m3️⃣\n\033[1;36m[^ctrl]"DEFAULT, 1);
	ft_putstr_fd("\033[3;45m/zoom--/\033[0;37m	   \033[3;45mcamera/", 1);
	ft_putstr_fd("\033[0;37m\033[1;36mᐊ ᐁ ᐅ\033[0;37m  	\033[3;45m", 1);
	ft_putstr_fd("obj(z--)/\033[0;37m \033[3;45mobj(x--)/\033[0;37m", 1);
	ft_putstr_fd(" \033[3;45mobj left/\033[0;37m\n\n\033[1;36mLM"DEFAULT, 1);
	ft_putstr_fd("\033[3;45m/select obj/\033[0;37m \
	\033[1;36mRM\033[0;37m\033[3;45m/select light/\033[0;37m\n", 1);
}

void	make_window(t_img *img, t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, \
		WIN_WIDTH, WIN_HEIGHT, "My beautiful miniRT window");
	img->ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->address = mlx_get_data_addr(img->ptr, \
		&img->bpp, &img->line_len, &img->endian);
	draw_loop(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, img->ptr, 0, 0);
	mlx_hook(data->mlx_window, 17, (1L << 0), exit_hook, data);
	mlx_hook(data->mlx_window, 2, (1L << 0), key_hook, data->objects[0]);
	mlx_mouse_hook(data->mlx_window, mouse_handler, data);
	mlx_loop(data->mlx);
}

void	default_values(t_data *data, t_img *img)
{
	data->mlx = NULL;
	data->mlx_window = NULL;
	data->img = img;
	data->ambient = NULL;
	data->camera = NULL;
	data->light = NULL;
	data->objects = NULL;
	data->qty = 0;
	data->select_obj = -1;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_img		img;

	if (argc == 2)
	{
		default_values(&data, &img);
		parser(argv[1], &data);
		if (!data.ambient || !data.camera || !data.light)
			exit_error("Corrupted file");
		print_usage();
		make_window(&img, &data);
	}
}
