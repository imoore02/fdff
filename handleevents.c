#include "mlx.h"
#include <math.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	// void *img_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 360, "Hello world!");

	mlx_loop(mlx_ptr); //recieves events from keyboard or mouse - called wout event

	mlx_key_hook(win_ptr, int (*funct_ptr)(), void *param ); //funct_ptr - pointer to the function that you want to be triggered when event occurs
	mlx_mouse_hook(win_ptr, int (*funct_ptr)(), void *param ); 
		//param address - passed to func everytime it is called - used to store params that might be needed
		//address specified in the mlx_*_hook calls - never used nor modified 
	mlx_expose_hook(win_ptr, int (*funct_ptr)(), void *param );
	mlx_loop_hook(mlx_ptr, int (*funct_ptr)(), void *param ); //
	return (0);
}