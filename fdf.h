#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

struct plot {
	int dimX;
	int dimY;
	int beginX;
	int endX;
	int beginY;
	int endY;
};

int 	draw_line(char *imgstr, int line_bytes, int beginX, int beginY, int endX, int endY);
void	pixel_put(char *imgstr, int pixel, int colour);
void make_picture(void *mlx_ptr, void *win_ptr, plot window);

#endif
