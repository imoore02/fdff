#include "mlx.h"
#include "fdf.h"

void	pixel_put(char *imgstr, int pixel, int colour)	
{
	imgstr[pixel + 0] = (colour) & 0xFF;
    imgstr[pixel + 1] = (colour >> 8) & 0xFF;
    imgstr[pixel + 2] = (colour >> 16) & 0xFF;
    imgstr[pixel + 3] = (colour >> 24);	
}