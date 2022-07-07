#include "mlx.h"

int	main(int argc, char *argv)
{
	int filedes;

	filedes = open(argv[1], RD_ONLY);
	/*void	*mlx_ptr;
	void	*win_ptr;
	void img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 200, 200, "Hello world!");
	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0999);
	mlx_string_put (mlx_ptr, win_ptr, 100, 100, 0999, "hello");
	mlx_loop(mlx_ptr); 
	return (0);*/
}