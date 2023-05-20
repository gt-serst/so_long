#include "../includes/so_long.h"

void	ft_put_sprite_to_window(t_program *program, t_graphic *graphic)
{
	printf("PATH:%s\n\n", graphic->path);
	program->sprite = ft_new_sprite(program->mlx, graphic->path);
	program->sprite_position.x = graphic->pixel_x;
	program->sprite_position.y = graphic->pixel_y;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
}
