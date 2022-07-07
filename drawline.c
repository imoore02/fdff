#include "mlx.h"
#include "fdf.h"

int		draw_line(char *imgstr, int line_bytes, t_plot graph);
void	pixel_put(char *imgstr, int pixel, int colour);
void	make_graph(char *imgstr, int line_bytes, t_plot window);
void	make_picture(void *mlx_ptr, void *win_ptr, t_plot window);

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_plot	window;

	window.dim_x = 640;
	window.dim_y = 360;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, window.dim_x, window.dim_y, "Hello world!");
	make_picture(mlx_ptr, win_ptr, window);
	mlx_loop(mlx_ptr);
	return (0);
}

void	make_picture(void *mlx_ptr, void *win_ptr, t_plot window)
{
	void	*img_ptr;
	char	*imgstr;
	int		line_bytes;
	int		endian;
	int		pixel_bits;

	img_ptr = mlx_new_image(mlx_ptr, window.dim_x, window.dim_y);
	imgstr = mlx_get_data_addr(img_ptr, &pixel_bits, &line_bytes, &endian);
	make_graph(imgstr, line_bytes, window);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}

void	make_graph(char *imgstr, int line_bytes, t_plot window)
{
	t_plot	graph;
	//Y axis
	graph.dim_x = window.dim_x - 20;
	graph.begin_x = (window.dim_x / 2) - (graph.dim_x / 2);
	graph.begin_y = window.dim_y / 2;
	graph.end_x = window.dim_x / 2;
	graph.end_y = (window.dim_y / 2) - (graph.dim_y / 2);
	draw_line(imgstr, line_bytes, graph);
//X axis	
}

int	draw_line(char *imgstr, int line_bytes, t_plot graph)
{
	int	x;
	int	y;
	int	slope_increment;
	int	slope_value_n_error;
	int	pixel;

	slope_increment = 2 * (graph.end_x - graph.begin_y);
	slope_value_n_error = slope_increment - (graph.end_x - graph.begin_x);
	x = graph.begin_x;
	y = graph.begin_y;
	while (x <= graph.end_x)
	{
		x++;
		pixel = (y * line_bytes) + (x * 4);
		pixel_put(imgstr, pixel, 0xFFFFFF);
		slope_value_n_error += slope_increment;
		if (slope_value_n_error >= 0)
		{
			y++;
			pixel = (y * line_bytes) + (x * 4);
			pixel_put(imgstr, pixel, 0xFFFFFF);
			slope_value_n_error -= 2 * (graph.end_x - graph.begin_x);
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
