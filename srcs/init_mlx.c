#include "../includes/so_long.h"

void	ft_init_mlx(char **matrix)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (mlx < 0)
		ft_exit(matrix, "mlx_init() failed");
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	mlx_loop(mlx);
}
