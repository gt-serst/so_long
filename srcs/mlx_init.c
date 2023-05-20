#include "../includes/so_long.h"

static t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void	ft_mlx_init(char **matrix)
{
	int			i;
	int			j;
	t_graphic	graphic;
	t_program	program;

	program.mlx = mlx_init();
	if (program.mlx < 0)
		ft_exit(matrix, "Mlx error");
	program.window = ft_new_window(program.mlx, 1920, 1080, "Hello world!");
	i = 0;
	graphic.pixel_y = 0;
	while (matrix[i])
	{
		graphic.pixel_x = 0;
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1')
			{
				graphic.path = "xpm/lava_tile1.xpm";
				ft_put_sprite_to_window(&program, &graphic);
			}
			if (matrix[i][j] == '0')
			{
				graphic.path = "xpm/tiles5.xpm";
				ft_put_sprite_to_window(&program, &graphic);
			}
			graphic.pixel_x += 64;
			j++;
		}
		graphic.pixel_y += 64;
		i++;
	}
	mlx_loop(program.mlx);
}
