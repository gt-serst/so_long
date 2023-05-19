#include "../includes/so_long.h"

static t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(mlx, widht, height, name);
	window.size.x = widht;
	window.size.y = height;
	return (window);
}

static t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void	ft_init_mlx(char **matrix)
{
	t_program	program;

	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 1980, 1080, "Hello world!");
	program.sprite = ft_new_sprite(program.mlx, "xpm/lava.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x, program.sprite_position.y);
	mlx_loop(program.mlx);
}
