#include "../includes/so_long.h"

int	ft_input(int key, t_program *program)
{
	if (key == 100)
		program->img[40].position.x += program->img[40].size.x;
	if (key == 113)
		program->img[40].position.x -= program->img[40].size.x;
	if (key == 115)
		program->img[40].position.y += program->img[40].size.x;
	if (key == 122)
		program->img[40].position.y -= program->img[40].size.x;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->img[40].reference, program->img[40].position.x,
		program->img[40].position.y);
	//printf("Key pressed -> %d\n", key);
	return (0);
}

void	ft_game_init(t_program *program)
{
	t_game	game;

	mlx_key_hook(program->window.reference, ft_input, program);
}
