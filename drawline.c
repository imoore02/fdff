#include "mlx.h"
#include <math.h>

int 	draw_line(char *imgstr, int line_bytes, int beginX, int beginY, int endX, int endY);
void	pixel_put(char *imgstr, int pixel, int colour);

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	plot 	window;

	plot.dimX = 640;
	plot.dimY = 360;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, plot.dimX, plot.dimY, "Hello world!");
	make_picture(mlx_ptr, win_ptr, plot.dimX, plot.dimY);
	mlx_loop(mlx_ptr); 
	return (0);
}

void make_picture(void *mlx_ptr, void *win_ptr, plot window)
{
	void 	*img_ptr;
	char	*imgstr;
	int 	line_bytes;
	int		endian;
	int		pixel_bits;

	img_ptr = mlx_new_image(mlx_ptr, window.dimX, window.dimY);
	imgstr = mlx_get_data_addr(img_ptr, &pixel_bits, &line_bytes, &endian);
	make_graph(window, imgstr, line_bytes);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}

void make_graph(i, char *imgstr, int line_bytes, plot window)
{
	plot graph;
	//Y axis
	graph.dimX = window.dimX - 20;
	graph.beginX = (window.dimX / 2) - (graph.dimX / 2);
	graph.beginY = window.dimY / 2;
	graph.endX = window.dimX / 2;
	graph.endY =  (window.dimY / 2) - (graph.dimY / 2);

	draw_line(imgstr, line_bytes, graph.beginX, graph.beginY, 640, 360);
	//X axis
}

int draw_line(char *imgstr, int line_bytes, int beginX, int beginY, int endX, int endY)
{
	int X;
	int Y;
	int slope_increment;
	int slope_value_n_error;

	slope_increment = 2 * (endY - beginY);
	slope_value_n_error = slope_increment - (endX - beginX); //2 * (endY - beginY) - (endX - beginX)
	X = beginX;
	Y = beginY;
	while (X <= endX)
	{
		X++;
		int pixel = (Y * line_bytes) + (X * 4);
		pixel_put(imgstr, pixel, 0xFFFFFF);
		slope_value_n_error += slope_increment;
		if (slope_value_n_error >= 0)
		{
			Y++;
			int pixel = (Y * line_bytes) + (X * 4);
			pixel_put(imgstr, pixel, 0xFFFFFF);
			slope_value_n_error -= 2 * (endX - beginX);
		}
	}
	return (0);
}

void	pixel_put(char *imgstr, int pixel, int colour)	
{
		imgstr[pixel + 0] = (colour) & 0xFF;
        imgstr[pixel + 1] = (colour >> 8) & 0xFF;
        imgstr[pixel + 2] = (colour >> 16) & 0xFF;
        imgstr[pixel + 3] = (colour >> 24);	
}